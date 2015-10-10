#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "resetdialog.h"
#include "cachemapper.h"
#include "coreState.h"
#include "codelist.h"
#include "instructionprogressdelegate.h"
#include "ramdelegate.h"
#include "helper.h"
#include "parser.h"
#include "parsererror.h"

#include <QObjectUserData>
#include <QStringList>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QMessageBox>
#include <QProgressBar>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    system(NULL)
{
    ui->setupUi(this);

    for(int i = (int)R_T0; i <= (int)R_S6;i++)
    {
        ui->registersTable2->insertRow(i - (int)R_T0);
        ui->registersTable2->setItem(i - (int)R_T0,0,new QTableWidgetItem(RegisterNames[i]));
        ui->registersTable2->setItem(i - (int)R_T0,1,new QTableWidgetItem(0));
    }

    for(int i = (int)R_T0; i <= (int)R_S6;i++)
    {
        ui->registersTable1->insertRow(i - (int)R_T0);
        ui->registersTable1->setItem(i - (int)R_T0,0,new QTableWidgetItem(RegisterNames[i]));
        ui->registersTable1->setItem(i - (int)R_T0,1,new QTableWidgetItem(0));
    }

    ui->registersTable2->insertRow(R_S6 - (int)R_T0 + 1);
    ui->registersTable2->setItem(R_S6 - (int)R_T0 + 1,0,new QTableWidgetItem("Total Cycles"));
    ui->registersTable2->setItem(R_S6 - (int)R_T0 + 1,1,new QTableWidgetItem(0));


    ui->registersTable1->insertRow(R_S6 - (int)R_T0 + 1);
    ui->registersTable1->setItem(R_S6 - (int)R_T0 + 1,0,new QTableWidgetItem("Total Cycles"));
    ui->registersTable1->setItem(R_S6 - (int)R_T0 + 1,1,new QTableWidgetItem(0));

    ui->memoryView->setItemDelegateForColumn(1,new RamDelegate);

    cacheSize = 4;
    cacheCycleCost = 4;
    ramCycleCost = 8;
    noFetchingBlocks = 4;
    coreAffinity = 0;

    this->setWindowTitle("Small Scale Multi Processor Simulator");

    Reset(cacheSize, cacheCycleCost, ramCycleCost, noFetchingBlocks,coreAffinity,
          NULL,NULL);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete system;
}

bool MainWindow::Cycle(int cycles,int coreIndex,bool countCycle)
{
    //if the work has already ended we can't issue a new cycle
    //just ignore the click
    if(system->HasWorkEnded())
    {
        //Reset(cacheSize, cacheCycleCost, ramCycleCost, noFetchingBlocks,coreAffinity);
        return false;
    }

    //no code no cycle
    if(system->Core(coreIndex)->GetCodeList() == NULL)
    {
        return false;
    }

    bool ended = !system->Cycle(cycles,coreIndex,countCycle);
    ShowState(coreIndex,ended);
    return ended;
}

bool MainWindow::ShowState(int coreIndex,bool hasEnded)
{
    CoreState* core = system->Core(coreIndex);

    QTableWidget* tables[] = {ui->registersTable1,ui->registersTable2};

    for(int i = (int)R_T0; i <= (int)R_S6;i++)
    {
        tables[coreIndex]->setItem(i - R_T0,1,new QTableWidgetItem(ToBinary( core->GetRegisterData((Register)i),8)));
    }

    tables[coreIndex]->setItem(R_S6 - R_T0 + 1,1,new QTableWidgetItem(QString::number( core->GetCycles() )));

    ui->totalCycles->setText(QString::number( system->TotalCycles() ));

    //we can only end the program if both cores have stoped
    if(hasEnded && system->HasWorkEnded())
    {
        QMessageBox msgBox;
        msgBox.setText("The program ended in " + QString::number( system->TotalCycles() ) + " cycles.");
        msgBox.exec();
        return false;
    }

    return true;
}

void MainWindow::Reset(int cacheSize, int cacheCycleCost, int ramCycleCost, int noFetchingBlocks,
                       int coreAffinity,CodeList* coreZeroCode,CodeList* coreOneCode)
{
    this->cacheSize = cacheSize;
    this->cacheCycleCost = cacheCycleCost;
    this->ramCycleCost = ramCycleCost;
    this->noFetchingBlocks = noFetchingBlocks;
    this->coreAffinity = coreAffinity;

    //remove old models
    ui->cacheViewC1->setModel(NULL);
    ui->cacheViewC2->setModel(NULL);
    ui->memoryView->setModel(NULL);

    //If no codelist was specified use the old one
    if(coreZeroCode == NULL && system != NULL)
    {
        coreZeroCode = system->Core(0)->GetCodeList();
    }

    if(coreOneCode == NULL && system != NULL)
    {
        coreOneCode = system->Core(1)->GetCodeList();
    }

    delete system;
    system = new SimulatedSystem(cacheSize, coreZeroCode, coreOneCode, cacheCycleCost, ramCycleCost, noFetchingBlocks);

    //UI of cache core 0
    ui->cacheViewC1->setModel(system->GetCacheModel(0));
    ui->cacheViewC1->show();

    //UI of cache core 1
    ui->cacheViewC2->setModel(system->GetCacheModel(1));
    ui->cacheViewC2->show();

    //UI of ram
    ui->memoryView->setModel(system->GetRamModel());
    ui->memoryView->show();

    PrepareCodeList(2);

    ShowState(0,false);
    ShowState(1,false);
}

void MainWindow::PrepareCodeList(int totalCores)
{
    QTableView* codeViews[] = {ui->codeList1,ui->codeList2};
    QCommandLinkButton* buttons[] = {ui->commandLinkButton,ui->commandLinkButton_2};

    for(int i = 0; i<totalCores; i++)
    {
        if(system->Core(i)->GetCodeList() != NULL)
        {
            codeViews[i]->setModel(system->Core(i)->GetCodeList()->GetModel());
            codeViews[i]->setItemDelegate(new InstructionDelegate);
            system->Core(i)->PrepareSimulation();
            buttons[i]->setText("Core Cycle");
        }
        else
        {
            buttons[i]->setText("Load Code");
        }
    }
}

CodeList* MainWindow::ParseCodeList(const QString fileName)
{
    CodeList* codelist = new CodeList;

    Parser parser;
    ParsingErrorCode error = parser.Parse(fileName,*codelist);

    //in case of errors show them to the user
    if(error != Parsing_OK)
    {
        QString errors;

        foreach(ParserError* error, parser.getErrors())
        {
            errors += error->what() + "\n";
        }

        QMessageBox msgBox;
        msgBox.setText(errors);
        msgBox.exec();

        //release the codelist since it's invalid
        delete codelist;
        codelist = NULL;
    }

    return codelist;
}

void MainWindow::on_commandLinkButton_pressed()
{
    ButtonPressed(0);
}

void MainWindow::on_actionReset_triggered()
{
    if(!ResetDialog::ExistsAlready())
    {
        ResetDialog* dialog = new ResetDialog(cacheSize,cacheCycleCost,ramCycleCost, noFetchingBlocks,coreAffinity,this);
        dialog->show();
    }
}

void MainWindow::on_commandLinkButton_2_clicked()
{
    ButtonPressed(1);
}

void MainWindow::ButtonPressed(int coreId)
{
    if(system->Core(coreId)->GetCodeList() == NULL)
    {
        LoadCode(coreId);
    }
    else
    {
        Cycle(1,coreId,true);
    }
}

void MainWindow::on_commandLinkButton_4_clicked()
{
    //cycle both cores
    //first the one with the affinity
    //and then the other one
    Cycle(1,coreAffinity,true);
    Cycle(1,!coreAffinity,false);
}

void MainWindow::on_actionCore_0_triggered()
{
    LoadCode(0);
}

void MainWindow::on_actionCore_1_triggered()
{
    LoadCode(1);
}

void MainWindow::LoadCode(int coreId)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Load code for Core ") + QString::number(coreId),"", tr("Files (*.*)"));

    if(!fileName.isEmpty())
    {
        CodeList* code = ParseCodeList(fileName);
        //if(code != NULL)
        {
            CodeList* codeCore1 = NULL;
            CodeList* codeCore2 = NULL;

            //choose the correct core to add this codeList
            //simply add NULL to the other one
            if(coreId == 0)
            {
                codeCore1 = code;
            }
            else
            {
                codeCore2 = code;
            }

            Reset(cacheSize, cacheCycleCost, ramCycleCost, noFetchingBlocks,coreAffinity,codeCore1,codeCore2);
        }
    }
}

void MainWindow::on_actionReset_2_triggered()
{
    Reset(cacheSize, cacheCycleCost, ramCycleCost, noFetchingBlocks,coreAffinity,NULL,NULL);
}

//remove
void MainWindow::on_commandLinkButton_clicked()
{

}
