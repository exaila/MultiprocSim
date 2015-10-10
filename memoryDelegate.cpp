#include "memoryDelegate.h"

#include <QSpinBox>

MemoryDelegate::MemoryDelegate(QObject* parent) :
    QItemDelegate(parent)
{
}

QWidget* MemoryDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option,const QModelIndex& index) const
{
    QSpinBox* editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);

    return editor;
}

void MemoryDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void MemoryDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,const QModelIndex& index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    model->setData(index, value, Qt::EditRole);
}

void MemoryDelegate::updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    editor->setGeometry(option.rect);
}

void MemoryDelegate::paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const
{

}
