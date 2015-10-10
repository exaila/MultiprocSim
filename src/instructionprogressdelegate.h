#ifndef INSTRUCTIONPROGRESSDELEGATE_H
#define INSTRUCTIONPROGRESSDELEGATE_H

#include <QStyledItemDelegate>

/**
 * @brief Used to draw the instruction model.
 */
class InstructionDelegate : public QStyledItemDelegate
{
public:
    InstructionDelegate();
    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // INSTRUCTIONPROGRESSDELEGATE_H
