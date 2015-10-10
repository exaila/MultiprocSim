#ifndef MEMORYMODEL_H
#define MEMORYMODEL_H

#include <QAbstractListModel>

class MemoryModel : public QAbstractListModel
{
    Q_OBJECT
private:
    int* memoryData;
    int memorySize;
public:
    MemoryModel(int* memoryData,int size,QObject *parent = 0);
    int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
    QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
};

#endif // MEMORYMODEL_H
