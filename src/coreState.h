#ifndef CORESTATE_H
#define CORESTATE_H

#include "enums.h"

class SimulatedSystem;
class InstructionState;
class CacheMapper;
class CodeList;
class Cache;
class Ram;

/**
 * @brief The CoreState class
 * It encapsualtes the state of a single core including
 * its cache, the code it is assigned to execute and its registers.
 *
 * Also this class provides all needed methods to read/write to memory
 * and run the code list.
 */
class CoreState
{
private:

    /**
     * @brief The cache of this core.
     */
    Cache* cache;

    /**
     * @brief The code this core will execute.
     */
    CodeList* codeList;

    /**
     * @brief A mapper used to map ram addresses to cache and back.
     */
    CacheMapper* mapper;

    /**
     * @brief The stateof the currently executed instruction.
     * Mainly used with memory access instructions which span through multiple system cycles.
     */
    InstructionState* currentInstructionState;

    /**
     * @brief A pointer to parent system.
     * Used to access system variables.
     */
    SimulatedSystem* parentSystem;

    /**
     * @brief The id of this core.
     * ex. 0 or 1
     */
    int coreId;

    /**
     * @brief The program counter of this core.
     * Indicates the next instruction which must be executed.
     */
    int programCounter;

    /**
     * @brief An array with all the registers of this core.
     */
    int registers[R_Total];

    /**
     * @brief Total number of cycles this core has spent.
     */
    int cycles;

    /**
     * @brief Indicates if the ram is locked by this core.
     */
    bool ramLocked;

public:

    CoreState(SimulatedSystem* parentSystem, int cacheSize, int coreId, Ram *ram, CodeList *codeList, int cacheCycleCost, int ramCycleCost, int numberOfBlocks, bool singleCore);

    InstructionStage GetCurrentStage();

    void PrepareSimulation();

    void Set(Register result, int value);

    void LoadRam(Register result, Register addressRegister, int offset);

    bool MemoryRead(InstructionState *instructionState, Register address, Register result, int offset);

    bool MemoryWrite(InstructionState *instructionState, Register address, Register data, int offset);

    bool TryLoadCache(Register result, Register addressRegister, int offset);

    /**
     * @brief Locks the ram form the given core.
     * @return true on success.
     */
    bool LockRam();

    int Get(Register result);

    void InvalidateCache();

    int GetPC();

    int GetCycles();

    CodeList* GetCodeList();

    Cache* GetCache();

    CacheMapper* GetCacheMapper();

    int CoreId();

    int GetRegisterData(Register registerName);

    void IncreasePC(int offset = 1);

    bool Cycle();

    /**
     * @brief Saves the data of the given register to the specified address (addressRegister + offset) in the ram.
     * @param dataRegister The register containing the data to save.
     * @param addressRegister The register containing the address to save at.
     * @param offset
     */
    void SaveToRam(Register dataRegister, Register addressRegister, int offset);

    /**
     * @brief Saves the data of the given register to the specified address (addressRegister + offset) in the cache.
     * @param dataRegister
     * @param addressRegister
     * @param offset
     */
    void SaveToCache(Register dataRegister, Register addressRegister, int offset);   

    bool HasEnded();

private:

    /**
     * @brief Tries to acquire the lock for the ram from the parent system.
     * @return
     */
    bool TryLockRam();

    int MemoryAccessImpl(InstructionState *instructionState, Register address, Register result, int offset);

    /**
     * @brief Returns the cycle cost of the current instruction.
     * Thsi method is not complete. It is used primarly in case of ram or cache access.
     * @return
     */
    int GetCurrentInstructionCost();
};

#endif // CORESTATE_H
