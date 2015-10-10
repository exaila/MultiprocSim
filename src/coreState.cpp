#include "coreState.h"
#include "cachemapper.h"
#include "codelist.h"
#include "cache.h"
#include "instructionState.h"
#include "simulatedSystem.h"
#include <QString>

CoreState::CoreState(SimulatedSystem* parentSystem,int cacheSize, int coreId,Ram* ram,CodeList* codeList,int cacheCycleCost, int ramCycleCost,
                     int numberOfBlocks,bool singleCore):
    currentInstructionState(NULL),
    programCounter(0),
    ramLocked(false),
    cycles(0),
    coreId(coreId),
    parentSystem(parentSystem)
{
    cache = new Cache(cacheSize);

    mapper = new CacheMapper(cache,ram,cacheCycleCost,ramCycleCost,numberOfBlocks);

    this->codeList = codeList;

    //set registers table to zero
    memset(registers,0,R_Total * sizeof(int));
}

InstructionStage CoreState::GetCurrentStage()
{
    if(currentInstructionState)
    {
        return currentInstructionState->Stage();
    }

    return IS_Simple;
}

void CoreState::PrepareSimulation()
{
    codeList->HighlightInstuction(0);
}

void CoreState::Set(Register result, int value)
{
    registers[result] = value;
}

void CoreState::LoadRam(Register result,Register addressRegister,int offset)
{
    //retrieve data
    int address = registers[addressRegister] + offset;
    int data = mapper->GetData(address,true);
    registers[result] = data;

    //release the ram for future use.
    parentSystem->LockRam(false);
    ramLocked = false;
}

void CoreState::SaveToCache(Register dataRegister,Register addressRegister,int offset)
{
    int address = registers[addressRegister] + offset;
    int data = registers[dataRegister];
    mapper->SetCacheData(address,data);
}

bool CoreState::HasEnded()
{
    if(codeList == NULL)
    {
        return true;
    }

    if(currentInstructionState == NULL)
    {
        return false;
    }

    return currentInstructionState->Stage() == IS_ProgramEnd;
}

void CoreState::SaveToRam(Register dataRegister,Register addressRegister,int offset)
{
    int address = registers[addressRegister] + offset;
    int data = registers[dataRegister];
    mapper->SetRamData(address,data);

    parentSystem->LockRam(false);
    ramLocked = false;
}

bool CoreState::MemoryRead(InstructionState* instructionState, Register address,Register result,int offset)
{
    //Hihglight the needed rows of ram and cache
    mapper->PrepareCacheTransfer(registers[(int)address] + offset,instructionState->Stage() == IS_Ram);
    if(MemoryAccessImpl(instructionState,address,result,offset))
    {
        //Stop the highlight since it is not needed anymore
        mapper->EndCacheTransfer(registers[(int)address]  + offset,instructionState->Stage() == IS_Ram,false);
        return true;
    }

    return false;
}

int CoreState::MemoryAccessImpl(InstructionState* instructionState, Register address,Register result,int offset)
{
    bool cycleCostPaid = ((instructionState->Stage() == IS_Ram) ? mapper->GetRamCost() : mapper->GetCacheCost()) <= instructionState->CyclesSpent();

    if(cycleCostPaid)
    {
        if(instructionState->Stage() == IS_Cache)
        {
            if(TryLoadCache(result,address,offset))
            {
                return 1;
            }
            else if(LockRam())
            {
                instructionState->SetStage(IS_Ram);
            }
            else
            {
                instructionState->SetStage(IS_Blocked);
            }
        }
        else if(instructionState->Stage() == IS_Ram )
        {
            LoadRam(result,address, offset);
            return 1;
        }
        else if(instructionState->Stage() == IS_Blocked)
        {
            if(LockRam())
            {
                instructionState->SetStage(IS_Ram);
            }
        }
    }
    return 0;
}

bool CoreState::MemoryWrite(InstructionState* instructionState, Register address,Register data,int offset)
{
    mapper->PrepareCacheTransfer(registers[(int)address] + offset,instructionState->Stage() == IS_Ram,true);

    bool cycleCostPaid = ((instructionState->Stage() == IS_Ram) ? mapper->GetRamCost() : mapper->GetCacheCost()) <= instructionState->CyclesSpent();

    if(cycleCostPaid)
    {
        mapper->EndCacheTransfer(registers[(int)address] + offset,instructionState->Stage() == IS_Ram,true);

        if(instructionState->Stage() == IS_Cache)
        {
            SaveToCache(data,address,offset);
            if(LockRam())
            {
                instructionState->SetStage(IS_Ram);
            }
            else
            {
                instructionState->SetStage(IS_Blocked);
            }
        }
        else if(instructionState->Stage() == IS_Ram )
        {
            SaveToRam(data,address,offset);
            return 1;
        }
        else if(instructionState->Stage() == IS_Blocked)
        {
            if(LockRam())
            {
                instructionState->SetStage(IS_Ram);
            }
        }
    }
    return 0;
}

bool CoreState::TryLoadCache(Register result,Register addressRegister,int offset)
{
    //retrieve the target address
    int address = registers[addressRegister] + offset;

    if(mapper->IsCacheValid(address))
    {
        int data = mapper->GetData(address,false);
        registers[result] = data;
        return true;
    }

    return false;
}

bool CoreState::LockRam()
{
    if(!ramLocked)
    {
        ramLocked = TryLockRam();
    }

    return ramLocked;
}

bool CoreState::TryLockRam()
{
    if(!parentSystem->IsRamLocked())
    {
        parentSystem->LockRam(true);
        ramLocked = true;
        return true;
    }
    return false;
}

int CoreState::Get(Register result)
{
    return registers[result];
}

void CoreState::InvalidateCache()
{
    mapper->InvalidateCache();
}

int CoreState::GetPC()
{
    return programCounter;
}

int CoreState::GetCycles()
{
    return cycles;
}

CodeList *CoreState::GetCodeList()
{
    return codeList;
}

Cache *CoreState::GetCache()
{
    return cache;
}

CacheMapper* CoreState::GetCacheMapper()
{
    return mapper;
}

int CoreState::CoreId()
{
    return coreId;
}

int CoreState::GetRegisterData(Register registerName)
{
    return registers[registerName];
}

void CoreState::IncreasePC(int offset /*= 1*/)
{
    programCounter += offset;
}

bool CoreState::Cycle()
{
    cycles++;

    if(currentInstructionState == NULL)
    {
        currentInstructionState = codeList->Get(programCounter)->GetNewState();
    }

    currentInstructionState->Stage();

    //run execute the next instruction and retrieve the
    //resulted program counter offset.
    int pcOffset = codeList->Get(programCounter)->Cycle(this,currentInstructionState);

    if(pcOffset != 0)
    {
        delete currentInstructionState;
        currentInstructionState = NULL;

        IncreasePC(pcOffset);

        currentInstructionState = codeList->Get(programCounter)->GetNewState();
    }

    if(pcOffset != 0 || currentInstructionState->Stage() == IS_ProgramEnd)
    {
        codeList->GetModel()->removeColumn(1);
    }

    //highlight the next instruction.
    codeList->HighlightInstuction(programCounter);

    if(currentInstructionState && (currentInstructionState->Stage() != IS_Simple && currentInstructionState->Stage() != IS_ProgramEnd ))
    {
        if(currentInstructionState->Stage() == IS_Blocked )
        {
            codeList->GetModel()->setItem(programCounter,1, new QStandardItem( QString("blocked") ));
        }
        else
        {
            codeList->GetModel()->setItem(programCounter,1,
                new QStandardItem (
                         QString::number(
                             currentInstructionState->CyclesSpent() + 1) +
                             "$" +
                             QString::number(GetCurrentInstructionCost()) ));
        }
    }

    return currentInstructionState->Stage() != IS_ProgramEnd;
}

int CoreState::GetCurrentInstructionCost()
{
    if(currentInstructionState->Stage() == IS_Simple)
    {
        return 1;
    }
    else
    {
        return ((currentInstructionState->Stage() == IS_Ram) ? mapper->GetRamCost() : mapper->GetCacheCost() );
    }
}
