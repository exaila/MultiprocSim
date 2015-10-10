#ifndef CACHE_H
#define CACHE_H

#include <QStandardItemModel>

/**
 * @brief The class used to simulate the cache for each core.
 */
class Cache
{
private:

    /**
    * @brief The actual data of the cache.
    * Each row represents a block consisting of several columns.
    *
    * 0 -> "Index" The index of this cache block
    * 1 -> "Valid" The validity bit
    * 2 -> "Tag" The tag of this block
    * 3 -> "Data" The actual data
    */
   QStandardItemModel* model;

public:

   Cache(int size);

   /**
    * @brief Retrive the underlying data model.
    * @return
    */
   QStandardItemModel* GetModel();
};

#endif // CACHE_H
