#ifndef RAM_H
#define RAM_H

class QStandardItemModel;

/**
 * @brief The Ram class
 * (Changed to level 2 cache)
 */
class Ram
{
public:

    Ram(int size);

    Ram(QStandardItemModel *model);

    QStandardItemModel* GetModel();

private:

    QStandardItemModel* memoryModel;

    bool readOnly;
};

#endif // RAM_H
