#include "resetdialog.h"
#include "ui_resetdialog.h"
#include "Mainwindow.h"
#include "Helper.h"

bool ResetDialog::exists = false;

ResetDialog::ResetDialog(int cacheSize, int cacheCost, int memoryCost, int noOfBlocks, int coreId, MainWindow *parent) :
    parentWnd(parent),
    QDialog(parent),
    ui(new Ui::ResetDialog)
{
    exists = true;
    ui->setupUi(this);

    ui->cacheCostField->setValue(cacheCost);
    ui->ramCostField->setValue(memoryCost);
    ui->blocksField->setCurrentIndex(  log2(noOfBlocks) - 1 );

    ui->cacheSizeField->setCurrentIndex(  log2(cacheSize) - 1 );

    ui->coreAffinity->setCurrentIndex(coreId);
    //ui->systemType->setCurrentIndex(singleCore ? 0:1);
}

bool ResetDialog::ExistsAlready()
{
    return exists;
}

ResetDialog::~ResetDialog()
{
    exists = false;
    delete ui;
}

void ResetDialog::closeEvent(QCloseEvent *event)
{
    delete this;
}

void ResetDialog::on_ResetDialog_accepted()
{
    int cacheSize = ui->cacheSizeField->currentText().toInt();
    int cacheCost = ui->cacheCostField->value();
    int memoryCost = ui->ramCostField->value();
    int noOfBlocks = ui->blocksField->currentText().toInt();

    parentWnd->Reset(cacheSize,cacheCost,memoryCost,noOfBlocks,ui->coreAffinity->currentIndex(),NULL,NULL);
}

void ResetDialog::on_buttonBox_accepted()
{
    on_ResetDialog_accepted();
    delete this;
}

void ResetDialog::on_buttonBox_rejected()
{
    delete this;
}

void ResetDialog::on_ResetDialog_finished(int result)
{

}

void ResetDialog::on_systemType_activated(int index)
{
    if(index == 0)
    {
        ui->coreAffinity->setCurrentIndex(0);
        ui->coreAffinity->setEnabled(false);
    }
    else
    {
        ui->coreAffinity->setEnabled(true);
    }
}
