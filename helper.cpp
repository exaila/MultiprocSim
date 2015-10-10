#include "helper.h"
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <QStandardItemModel>

bool Contains(const QString array[],int startIndex,int arraySize,const QString& targetValue,int& index)
{
    for(int i = startIndex; i < arraySize; i++)
    {
        if(targetValue.contains(array[i]))
        {
            index = i;
            return true;
        }
    }

    return false;
}

void RandomInitialize()
{
    srand(time(0));
}

int RandomInt(int max)
{
    return rand() % max;
}

int RandomInt(int min, int max)
{
    return (rand() % (min + max)) - min;
}

QString ToBinary(int number, int digitNumber)
{
    QString value;

	//initialize the result to zeroes
    value.fill('0',digitNumber);
	
	//get the short representation of the number
	//ex. 3 -> 101
    QString binary = QString::number( number,2);

	//replace the last characters of value with binary
	//ex. 3 -> 101 -> 000101
    value.replace(digitNumber - binary.length(),binary.length(),binary);

    return value;
}

void HighlightRows(QStandardItemModel* model,int start, int end, const QColor& color)
{
    for(int i = start; i<end; i++)
    {
        HighlightSingleRow(model, i ,color);
    }
}

void HighlightSingleRow(QStandardItemModel* model,int row,const QColor& color)
{
    //change the color of the given row for each column.
    int cols = model->columnCount();
    for(int i = 0 ; i < cols;i++)
    {
        model->item(row,i)->setBackground(QBrush(color));
    }
}


void Trim(QString &str)
{
    while(str.endsWith(' '))
    {
        str.chop(1);
    }
    
    while(str.startsWith(' '))
    {
        str.remove(0,1);
    }
}
