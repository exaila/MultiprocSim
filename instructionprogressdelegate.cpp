#include "instructionprogressdelegate.h"
#include "instruction.h"
#include <QApplication>
#include <QPainter>
#include <QString>

InstructionDelegate::InstructionDelegate()
{
}

void InstructionDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.column() == 0)
    {
        QStyledItemDelegate::paint(painter, option, index);
    }
    else if (index.column() == 1)
    {
        QStringList args = index.data().toString().split('$',QString::SkipEmptyParts);

        if(args.size() == 0)
        {
            QStyledItemDelegate::paint(painter, option, index);
            return;
        }

        QString strData = args.at(0);

        //instruction is blocked.
        if(strData == "blocked")
        {
            QStyleOptionHeader label;
            label.text = " Blocked";
            label.rect = option.rect;
            QApplication::style()->drawControl(QStyle::CE_HeaderLabel, &label, painter);
            return;
        }

        bool ok;
        int intData = strData.toInt(&ok);

        if(!ok)
        {
            QStyledItemDelegate::paint(painter, option, index);
            return;
        }

        // Instruction is loading/writing data

        QStyleOptionProgressBar progressBarOption;
        progressBarOption.rect = option.rect;
        progressBarOption.minimum = 0;
        progressBarOption.maximum = args.at(1).toInt(&ok);
        progressBarOption.progress = intData;
        progressBarOption.text = strData + "/ " + args.at(1);
        progressBarOption.textVisible = true;

        QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);

    }
}
