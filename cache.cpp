#include "cache.h"

#include "helper.h"

Cache::Cache(int size)
{
    model = new QStandardItemModel;

    //Add randomized data.
    for (int row = 0; row < size; row++)
    {
        QStandardItem* data = new QStandardItem(ToBinary(RandomInt(15),8));
        data->setFlags(0);

        int ad =  row / size;

        QStandardItem* address = new QStandardItem( ToBinary(ad,6 - log2(size) ) );
        address->setFlags(0);

        QString indexString = ToBinary( row,log2(size) );

        QStandardItem* index = new QStandardItem(indexString);
        index->setFlags(0);

        // Initialize each block always to invalid state.
        QStandardItem* valid = new QStandardItem(QString("false"));
        valid->setFlags(0);

        // add the data to the model.
        model->setItem(row, 0, index);
        model->setItem(row, 1, valid);
        model->setItem(row, 2, address);
        model->setItem(row, 3, data);
    }

    // Add column labels.
    model->setHorizontalHeaderItem(0,new QStandardItem("Index"));
    model->setHorizontalHeaderItem(1,new QStandardItem("Valid"));
    model->setHorizontalHeaderItem(2,new QStandardItem("Tag"));
    model->setHorizontalHeaderItem(3,new QStandardItem("Data"));
}

QStandardItemModel* Cache::GetModel()
{
    return model;
}
