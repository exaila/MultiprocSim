#ifndef RAMDELEGATE_H
#define RAMDELEGATE_H

#include <QStyledItemDelegate>

/**
 * @brief Used to draw and edit the elements of Ram model.
 */
class RamDelegate: public QStyledItemDelegate
{
public:
    RamDelegate();

    QWidget *createEditor(QWidget *parent,  const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setModelData(QWidget *editor,  QAbstractItemModel *model, const QModelIndex &index) const;
};

#endif // RAMDELEGATE_H
