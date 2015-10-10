#include "memoryModel.h"

#include <QVariant>

MemoryModel::MemoryModel(int* memoryData,int size,QObject* parent) :
    QAbstractListModel(parent)
{
    this->memoryData = memoryData;
    memorySize = size;
}

int MemoryModel::rowCount(const QModelIndex& parent) const
{
    return memorySize;
}

QVariant MemoryModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole)
    {
        index.row();
    }

    if(index.row() < memorySize)
    {
        return QString::number(memoryData[index.row()]);
    }
    else
    {
        return QVariant();
    }
}

QVariant MemoryModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
             return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("Column %1").arg(section);
    else
        return QString("Row %1").arg(section);
}

