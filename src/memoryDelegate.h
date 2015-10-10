#ifndef MEMORYDELEGATE_H
#define MEMORYDELEGATE_H

#include <QItemDelegate>

class MemoryDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit MemoryDelegate(QObject* parent = 0);
    
    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,const QModelIndex& index) const;
    void setEditorData(QWidget* editor, const QModelIndex& index) const;
    void setModelData(QWidget* editor, QAbstractItemModel* model,const QModelIndex& index) const;
    void updateEditorGeometry(QWidget* editor,const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void paint( QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index ) const;
signals:
    
public slots:
    
};

#endif // MEMORYDELEGATE_H
