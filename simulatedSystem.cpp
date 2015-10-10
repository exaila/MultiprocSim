#include "simulatedSystem.h"
#include "helper.h"
#include "cache.h"
#include "ram.h"
#include "cachemapper.h"
#include "coreState.h"

SimulatedSystem::SimulatedSystem(int cacheSize,CodeList* codeList0,CodeList* codeList1, int cacheCycleCost, int ramCycleCost, int noFetchingBlocks):
    ramLocked(false)
{
    InitializeModels(64);

    totalCycles = 0;

    cacheCost = cacheCycleCost;
    ramCost = ramCycleCost;

    //build the two cores
    cores[0] = new CoreState(this,cacheSize,0,ram,codeList0, cacheCycleCost, ramCycleCost, noFetchingBlocks,true);
    cores[1] = new CoreState(this,cacheSize,1,ram,codeList1, cacheCycleCost, ramCycleCost, noFetchingBlocks,true);

}

SimulatedSystem::~SimulatedSystem()
{
    for(int i = 0; i < 2; i++)
    {
        delete cores[i];
    }
}

bool SimulatedSystem::Cycle(int cycles, int coreIndex,bool countCycle)
{
    if(countCycle)
    {
        totalCycles += cycles;
    }
    return cores[coreIndex]->Cycle();
}

CoreState *SimulatedSystem::Core(int coreIndex)
{
    if(coreIndex >= 2)
    {
        return NULL;
    }

    return cores[coreIndex];
}

QStandardItemModel* SimulatedSystem::GetRamModel()
{
    return ram->GetModel();
}

QStandardItemModel* SimulatedSystem::GetCacheModel(int coreId)
{
    return cores[coreId]->GetCache()->GetModel();
}

int SimulatedSystem::TotalCycles()
{
    return totalCycles;
}

int SimulatedSystem::CacheCost()
{
    return cacheCost;
}

int SimulatedSystem::RamCost()
{
    return ramCost;
}

Cache *SimulatedSystem::GetCache(int coreId)
{
    return cores[coreId]->GetCache();
}

bool SimulatedSystem::HasWorkEnded()
{
    return cores[0]->HasEnded() && (cores[1]->HasEnded());
}

void SimulatedSystem::InitializeModels(int ramSize)
{    
    ram = new Ram(ramSize);
}

bool SimulatedSystem::IsRamLocked()
{
    return ramLocked;
}

void SimulatedSystem::LockRam(bool lock)
{
    ramLocked = lock;
}
