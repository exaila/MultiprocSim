#ifndef SIMULATEDSYSTEM_H
#define SIMULATEDSYSTEM_H

#include <QQueue>
#include <QStandardItemModel>

class Cache;
class Ram;
class CoreState;
class CodeList;

/**
 * @brief The SimulatedSystem is the core class of the simulation.
 * It inludes the cores and the ram models.
 */
class SimulatedSystem
{
private:

    CoreState* cores[2];

    /**
     * @brief The ram model
     * (changed to level 2 cache)
     */
    Ram* ram;

    int cacheCost;

    int ramCost;

    int totalCycles;

    int arraySize;

    int arrayStart;

    bool ramLocked;
public:

    SimulatedSystem(int cacheSize, CodeList *codeList0, CodeList *codeList1, int cacheCycleCost, int ramCycleCost, int noFetchingBlocks);

    ~SimulatedSystem();

    bool Cycle(int cycles,int coreIndex, bool countCycle);

    CoreState* Core(int coreIndex);

    QStandardItemModel* GetRamModel();

    QStandardItemModel* GetCacheModel(int coreId);

    int TotalCycles();

    int CacheCost();

    int RamCost();

    bool IsRamLocked();

    void LockRam(bool lock);

    Cache* GetCache(int coreId);

    bool HasWorkEnded();

private:
    void InitializeModels(int ramSize);
};

#endif // SIMULATEDSYSTEM_H
