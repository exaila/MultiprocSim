/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionReset;
    QAction *actionQuit;
    QAction *actionCore_0;
    QAction *actionCore_1;
    QAction *actionReset_2;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_9;
    QSplitter *splitter_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QTableWidget *registersTable1;
    QCommandLinkButton *commandLinkButton;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTableView *codeList1;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableView *cacheViewC1;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_2;
    QWidget *layoutWidget4;
    QGridLayout *gridLayout_2;
    QTableWidget *registersTable2;
    QCommandLinkButton *commandLinkButton_2;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_4;
    QTableView *codeList2;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QTableView *cacheViewC2;
    QGroupBox *groupBox_3;
    QCommandLinkButton *commandLinkButton_4;
    QLineEdit *totalCycles;
    QLabel *label;
    QWidget *layoutWidget7;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_6;
    QTableView *memoryView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLoad;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1083, 753);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        actionCore_0 = new QAction(MainWindow);
        actionCore_0->setObjectName(QStringLiteral("actionCore_0"));
        actionCore_1 = new QAction(MainWindow);
        actionCore_1->setObjectName(QStringLiteral("actionCore_1"));
        actionReset_2 = new QAction(MainWindow);
        actionReset_2->setObjectName(QStringLiteral("actionReset_2"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAutoFillBackground(false);
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8->setTextFormat(Qt::AutoText);
        label_8->setScaledContents(false);
        label_8->setOpenExternalLinks(true);

        horizontalLayout->addWidget(label_8);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAutoFillBackground(false);
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7->setOpenExternalLinks(true);

        horizontalLayout->addWidget(label_7);

        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAutoFillBackground(false);
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9->setOpenExternalLinks(true);

        horizontalLayout->addWidget(label_9);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        splitter_4 = new QSplitter(centralwidget);
        splitter_4->setObjectName(QStringLiteral("splitter_4"));
        splitter_4->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        splitter_3 = new QSplitter(layoutWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        groupBox = new QGroupBox(splitter_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_5 = new QGridLayout(groupBox);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        splitter = new QSplitter(groupBox);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        registersTable1 = new QTableWidget(layoutWidget1);
        if (registersTable1->columnCount() < 2)
            registersTable1->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        registersTable1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        registersTable1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        registersTable1->setObjectName(QStringLiteral("registersTable1"));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        registersTable1->setFont(font);
        registersTable1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        registersTable1->setShowGrid(false);
        registersTable1->setWordWrap(false);
        registersTable1->horizontalHeader()->setDefaultSectionSize(80);
        registersTable1->horizontalHeader()->setMinimumSectionSize(35);
        registersTable1->horizontalHeader()->setStretchLastSection(true);
        registersTable1->verticalHeader()->setVisible(false);

        gridLayout->addWidget(registersTable1, 0, 0, 1, 1);

        commandLinkButton = new QCommandLinkButton(layoutWidget1);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setShortcut(QStringLiteral("Space, Return, N"));
        commandLinkButton->setAutoRepeat(true);

        gridLayout->addWidget(commandLinkButton, 1, 0, 1, 1);

        splitter->addWidget(layoutWidget1);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        codeList1 = new QTableView(layoutWidget2);
        codeList1->setObjectName(QStringLiteral("codeList1"));
        codeList1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        codeList1->setDragDropMode(QAbstractItemView::NoDragDrop);
        codeList1->setIconSize(QSize(10, 10));
        codeList1->setTextElideMode(Qt::ElideLeft);
        codeList1->setShowGrid(false);
        codeList1->setGridStyle(Qt::NoPen);
        codeList1->setWordWrap(false);
        codeList1->setCornerButtonEnabled(false);
        codeList1->horizontalHeader()->setVisible(false);
        codeList1->horizontalHeader()->setDefaultSectionSize(180);
        codeList1->horizontalHeader()->setMinimumSectionSize(180);
        codeList1->horizontalHeader()->setStretchLastSection(false);
        codeList1->verticalHeader()->setVisible(false);
        codeList1->verticalHeader()->setDefaultSectionSize(18);
        codeList1->verticalHeader()->setHighlightSections(false);
        codeList1->verticalHeader()->setMinimumSectionSize(18);

        verticalLayout_3->addWidget(codeList1);

        splitter->addWidget(layoutWidget2);
        layoutWidget3 = new QWidget(splitter);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget3);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        cacheViewC1 = new QTableView(layoutWidget3);
        cacheViewC1->setObjectName(QStringLiteral("cacheViewC1"));
        cacheViewC1->setFont(font);
        cacheViewC1->setShowGrid(true);
        cacheViewC1->horizontalHeader()->setVisible(true);
        cacheViewC1->horizontalHeader()->setStretchLastSection(true);
        cacheViewC1->verticalHeader()->setVisible(false);
        cacheViewC1->verticalHeader()->setCascadingSectionResizes(false);
        cacheViewC1->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(cacheViewC1);

        splitter->addWidget(layoutWidget3);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        splitter_3->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter_2 = new QSplitter(groupBox_2);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget4 = new QWidget(splitter_2);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        gridLayout_2 = new QGridLayout(layoutWidget4);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        registersTable2 = new QTableWidget(layoutWidget4);
        if (registersTable2->columnCount() < 2)
            registersTable2->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        registersTable2->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        registersTable2->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        registersTable2->setObjectName(QStringLiteral("registersTable2"));
        registersTable2->setFont(font);
        registersTable2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        registersTable2->setShowGrid(false);
        registersTable2->setWordWrap(false);
        registersTable2->horizontalHeader()->setVisible(true);
        registersTable2->horizontalHeader()->setCascadingSectionResizes(false);
        registersTable2->horizontalHeader()->setDefaultSectionSize(80);
        registersTable2->horizontalHeader()->setMinimumSectionSize(35);
        registersTable2->horizontalHeader()->setStretchLastSection(true);
        registersTable2->verticalHeader()->setVisible(false);

        gridLayout_2->addWidget(registersTable2, 0, 0, 1, 1);

        commandLinkButton_2 = new QCommandLinkButton(layoutWidget4);
        commandLinkButton_2->setObjectName(QStringLiteral("commandLinkButton_2"));
        commandLinkButton_2->setAutoRepeat(true);

        gridLayout_2->addWidget(commandLinkButton_2, 1, 0, 1, 2);

        splitter_2->addWidget(layoutWidget4);
        layoutWidget5 = new QWidget(splitter_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        verticalLayout_5 = new QVBoxLayout(layoutWidget5);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget5);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_5->addWidget(label_4);

        codeList2 = new QTableView(layoutWidget5);
        codeList2->setObjectName(QStringLiteral("codeList2"));
        codeList2->setShowGrid(false);
        codeList2->setGridStyle(Qt::NoPen);
        codeList2->setWordWrap(false);
        codeList2->setCornerButtonEnabled(false);
        codeList2->horizontalHeader()->setVisible(false);
        codeList2->horizontalHeader()->setDefaultSectionSize(180);
        codeList2->horizontalHeader()->setMinimumSectionSize(180);
        codeList2->horizontalHeader()->setStretchLastSection(false);
        codeList2->verticalHeader()->setVisible(false);
        codeList2->verticalHeader()->setDefaultSectionSize(18);
        codeList2->verticalHeader()->setHighlightSections(false);
        codeList2->verticalHeader()->setMinimumSectionSize(18);

        verticalLayout_5->addWidget(codeList2);

        splitter_2->addWidget(layoutWidget5);
        layoutWidget6 = new QWidget(splitter_2);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        verticalLayout_4 = new QVBoxLayout(layoutWidget6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget6);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_4->addWidget(label_5);

        cacheViewC2 = new QTableView(layoutWidget6);
        cacheViewC2->setObjectName(QStringLiteral("cacheViewC2"));
        cacheViewC2->setFont(font);
        cacheViewC2->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        cacheViewC2->horizontalHeader()->setStretchLastSection(true);
        cacheViewC2->verticalHeader()->setVisible(false);

        verticalLayout_4->addWidget(cacheViewC2);

        splitter_2->addWidget(layoutWidget6);

        gridLayout_4->addWidget(splitter_2, 0, 0, 1, 1);

        splitter_3->addWidget(groupBox_2);

        verticalLayout->addWidget(splitter_3);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(500, 70));
        groupBox_3->setMaximumSize(QSize(16777215, 70));
        groupBox_3->setFlat(false);
        commandLinkButton_4 = new QCommandLinkButton(groupBox_3);
        commandLinkButton_4->setObjectName(QStringLiteral("commandLinkButton_4"));
        commandLinkButton_4->setGeometry(QRect(10, 20, 151, 39));
        commandLinkButton_4->setAutoRepeat(true);
        totalCycles = new QLineEdit(groupBox_3);
        totalCycles->setObjectName(QStringLiteral("totalCycles"));
        totalCycles->setGeometry(QRect(320, 30, 121, 16));
        totalCycles->setReadOnly(true);
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 30, 121, 16));

        verticalLayout->addWidget(groupBox_3);

        verticalLayout->setStretch(0, 1);
        splitter_4->addWidget(layoutWidget);
        layoutWidget7 = new QWidget(splitter_4);
        layoutWidget7->setObjectName(QStringLiteral("layoutWidget7"));
        verticalLayout_6 = new QVBoxLayout(layoutWidget7);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(layoutWidget7);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_6->addWidget(label_6);

        memoryView = new QTableView(layoutWidget7);
        memoryView->setObjectName(QStringLiteral("memoryView"));
        memoryView->setFont(font);
        memoryView->setProperty("showDropIndicator", QVariant(false));
        memoryView->setSelectionMode(QAbstractItemView::NoSelection);
        memoryView->setSelectionBehavior(QAbstractItemView::SelectRows);
        memoryView->horizontalHeader()->setVisible(false);
        memoryView->horizontalHeader()->setStretchLastSection(true);
        memoryView->verticalHeader()->setVisible(false);
        memoryView->verticalHeader()->setHighlightSections(false);

        verticalLayout_6->addWidget(memoryView);

        splitter_4->addWidget(layoutWidget7);

        gridLayout_3->addWidget(splitter_4, 0, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 10);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1083, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuLoad = new QMenu(menuFile);
        menuLoad->setObjectName(QStringLiteral("menuLoad"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionReset);
        menuFile->addAction(menuLoad->menuAction());
        menuFile->addAction(actionReset_2);
        menuLoad->addAction(actionCore_0);
        menuLoad->addAction(actionCore_1);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Multicore", 0));
        actionReset->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionCore_0->setText(QApplication::translate("MainWindow", "Core 0", 0));
        actionCore_1->setText(QApplication::translate("MainWindow", "Core 1", 0));
        actionReset_2->setText(QApplication::translate("MainWindow", "Reset", 0));
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"http://europa.eu/index_el.htm\"><img src=\":/images/images/b.png\"/></a></p></body></html>", "www.kati.gr"));
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"http://www.digitalplan.gov.gr/portal/\"><img src=\":/images/images/a.png\"/></a></p></body></html>", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><a href=\"http://www.espa.gr/el/Pages/Default.aspx\"><img src=\":/images/images/c.png\"/></a></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Core 0", 0));
        QTableWidgetItem *___qtablewidgetitem = registersTable1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Register", 0));
        QTableWidgetItem *___qtablewidgetitem1 = registersTable1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Value", 0));
        commandLinkButton->setText(QApplication::translate("MainWindow", "Core Cycle", 0));
        label_2->setText(QApplication::translate("MainWindow", "Code", 0));
        label_3->setText(QApplication::translate("MainWindow", "L1 Cache", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Core 1", 0));
        QTableWidgetItem *___qtablewidgetitem2 = registersTable2->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Register", 0));
        QTableWidgetItem *___qtablewidgetitem3 = registersTable2->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Value", 0));
        commandLinkButton_2->setText(QApplication::translate("MainWindow", "Core Cycle", 0));
        label_4->setText(QApplication::translate("MainWindow", "Code", 0));
        label_5->setText(QApplication::translate("MainWindow", "L1 Cache", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "System", 0));
        commandLinkButton_4->setText(QApplication::translate("MainWindow", "System Cycle", 0));
        label->setText(QApplication::translate("MainWindow", "Total system cycles", 0));
        label_6->setText(QApplication::translate("MainWindow", "L2 Cache", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuLoad->setTitle(QApplication::translate("MainWindow", "Load Code", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
