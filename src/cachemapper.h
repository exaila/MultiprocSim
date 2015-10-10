#ifndef CACHEMAPPER_H
#define CACHEMAPPER_H

class Cache;
class Ram;

/**
 * @brief A helper class used to map data from ram to cache.
 */
class CacheMapper
{
public:
    CacheMapper(Cache* cache,Ram* ram,int cacheCost,int ramCost, int fetchBlocks);

    /**
     * @brief Returns the data from the given address.
     * If memory is true this will also transfer the data to the cache.
     * @param address
     * @param memory
     * @return
     */
    int GetData(int address, bool transferToCache);

    /**
     * @brief Returns if the block for the given address is valid.
     * @param address
     * @return
     */
    bool IsCacheValid(int address);

    /**
     * @brief Invalidate all Cache blocks.
     */
    void InvalidateCache();

    /**
     * @brief Returns the index of the block for the given address.
     * @param address
     * @return
     */
    int GetCacheBlock(int address);

    QString GetTag(int address);

    /**
     * @brief Highlights the needed blocks of cache and ram.
     * @param startAddress
     * @param highlightRam
     * @param single
     */
    void PrepareCacheTransfer(int startAddress, bool highlightRam, bool single = false);

    /**
     * @brief Removes the highlight the specified blocks of cache and ram.
     * @param startAddress
     * @param highlightRam
     * @param single
     */
    void EndCacheTransfer(int startAddress, bool highlightRam, bool single);

    void SetRamData(int address, int data);

    void SetCacheData(int address, int data);

    int GetRamCost() const;

    void SetRamCost(int value);

    int GetCacheCost() const;

    void SetCacheCost(int value);

private:

    /**
     * @brief Transfers all needed data of ram from startAddress til startAddress + number Of BLocks To Transfer
     * @param startAddress
     */
    void TransferBlocks(int startAddress);

    /**
     * @brief Transfers the data from the block of the given address to the given cacheIndex.
     * @param address
     * @param cacheIndex
     */
    void TransferToCache(int address, int cacheIndex);

    /**
     * @brief Returns the first and last index of the cache for the addresses [startAdress, startAddress + blockToTransfer]
     * @param startAddress
     * @param start
     * @param end
     */
    void GetTransferBlocksIndices(int startAddress,int& start, int &end);

    Ram* ram;

    Cache* cache;

    int cacheSize;

    int ramCost;

    int cacheCost;

    int fetchBlocks;

};

#endif // CACHEMAPPER_H
