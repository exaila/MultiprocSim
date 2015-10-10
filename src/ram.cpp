#include "ram.h"
#include "helper.h"
#include <QStandardItemModel>

Ram::Ram(int size)
{
    readOnly = false;
    memoryModel = new QStandardItemModel;

    for (int row = 0; row < size; ++row)
    {
        QStandardItem* data = new QStandardItem(ToBinary(RandomInt(32),8));
        data->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);

        QStandardItem* address = new QStandardItem(ToBinary(row,log2(size)));
        address->setFlags(0);

        memoryModel->setItem(row, 0, address);
        memoryModel->setItem(row, 1, data);
    }

    memoryModel->setHorizontalHeaderItem(0,new QStandardItem("Address"));
    memoryModel->setHorizontalHeaderItem(1,new QStandardItem("Data"));        
}

Ram::Ram(QStandardItemModel* model)
{
    readOnly = true;
    memoryModel = model;
}

QStandardItemModel* Ram::GetModel()
{
    return memoryModel;
}
