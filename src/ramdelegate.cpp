#include "ramdelegate.h"
#include "helper.h"
#include <QLineEdit>

RamDelegate::RamDelegate()
{
}

QWidget *RamDelegate::createEditor(QWidget *parent,  const QStyleOptionViewItem &option,  const QModelIndex &index) const
{
    QLineEdit* lineEdit = new QLineEdit(parent);
    QValidator* validator = new QRegExpValidator(QRegExp("[10]{8}"));
    lineEdit->setValidator(validator);

    return lineEdit;
}

void RamDelegate::setModelData(QWidget *editor,  QAbstractItemModel *model, const QModelIndex &index) const
{
    bool ok;
    model->setData(index,QVariant( ToBinary(((QLineEdit*)editor)->text().toInt(&ok,2),8)  ));
}
