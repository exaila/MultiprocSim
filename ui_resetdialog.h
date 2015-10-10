/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *cacheSizeField;
    QLabel *label_4;
    QSpinBox *cacheCostField;
    QLabel *label_5;
    QSpinBox *ramCostField;
    QLabel *label_6;
    QComboBox *blocksField;
    QLabel *label_7;
    QComboBox *coreAffinity;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName(QStringLiteral("ResetDialog"));
        ResetDialog->resize(337, 172);
        ResetDialog->setFocusPolicy(Qt::StrongFocus);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ResetDialog->setWindowIcon(icon);
        ResetDialog->setModal(false);
        layoutWidget = new QWidget(ResetDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 321, 237));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        cacheSizeField = new QComboBox(layoutWidget);
        cacheSizeField->setObjectName(QStringLiteral("cacheSizeField"));

        formLayout->setWidget(0, QFormLayout::FieldRole, cacheSizeField);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        cacheCostField = new QSpinBox(layoutWidget);
        cacheCostField->setObjectName(QStringLiteral("cacheCostField"));
        cacheCostField->setMinimum(1);
        cacheCostField->setMaximum(8);
        cacheCostField->setValue(4);

        formLayout->setWidget(1, QFormLayout::FieldRole, cacheCostField);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        ramCostField = new QSpinBox(layoutWidget);
        ramCostField->setObjectName(QStringLiteral("ramCostField"));
        ramCostField->setMinimum(2);
        ramCostField->setMaximum(16);

        formLayout->setWidget(2, QFormLayout::FieldRole, ramCostField);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        blocksField = new QComboBox(layoutWidget);
        blocksField->setObjectName(QStringLiteral("blocksField"));

        formLayout->setWidget(3, QFormLayout::FieldRole, blocksField);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_7);

        coreAffinity = new QComboBox(layoutWidget);
        coreAffinity->setObjectName(QStringLiteral("coreAffinity"));
        coreAffinity->setEnabled(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, coreAffinity);

        buttonBox = new QDialogButtonBox(layoutWidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(5, QFormLayout::FieldRole, buttonBox);


        verticalLayout->addLayout(formLayout);


        retranslateUi(ResetDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResetDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResetDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QApplication::translate("ResetDialog", "Settings", 0));
        label->setText(QApplication::translate("ResetDialog", "L1 Cache Size", 0));
        cacheSizeField->clear();
        cacheSizeField->insertItems(0, QStringList()
         << QApplication::translate("ResetDialog", "2", 0)
         << QApplication::translate("ResetDialog", "4", 0)
         << QApplication::translate("ResetDialog", "8", 0)
         << QApplication::translate("ResetDialog", "16", 0)
        );
        label_4->setText(QApplication::translate("ResetDialog", "L1 Cache hit cost in cycles", 0));
        label_5->setText(QApplication::translate("ResetDialog", "L2 Cache hit cost ", 0));
        label_6->setText(QApplication::translate("ResetDialog", "Number of blocks to transfer", 0));
        blocksField->clear();
        blocksField->insertItems(0, QStringList()
         << QApplication::translate("ResetDialog", "2", 0)
         << QApplication::translate("ResetDialog", "4", 0)
         << QApplication::translate("ResetDialog", "8", 0)
        );
        label_7->setText(QApplication::translate("ResetDialog", "L2 Cache Access Priority", 0));
        coreAffinity->clear();
        coreAffinity->insertItems(0, QStringList()
         << QApplication::translate("ResetDialog", "Core 0", 0)
         << QApplication::translate("ResetDialog", "Core 1", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
