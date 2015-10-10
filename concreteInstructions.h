#ifndef CONCRETEINSTRUCTIONS_H
#define CONCRETEINSTRUCTIONS_H

#include <QString>
#include "instruction.h"
#include "enums.h"

//revised many times!

class InstructionLoadImed : public Instruction
{
public:
    virtual ~InstructionLoadImed(){}
    InstructionLoadImed(Register result,int value);
    int virtual Cycle(CoreState* coreState,InstructionState* instructionState);
};

class InstructionArithmetic : public Instruction
{
    private:
        ArithmeticOperation operation;

    public:
        virtual ~InstructionArithmetic(){}
        InstructionArithmetic& Set(ArithmeticOperation operation,Register result,Register a1,Register a2);
        InstructionArithmetic& Set(ArithmeticOperation operation,Register result,Register a1,int a2);
        int virtual Cycle(CoreState* coreState,InstructionState* instructionState);
};

class InstructionBranch : public Instruction
{
    private:
        BranchOperation operation;
    public:
        virtual ~InstructionBranch(){}
        InstructionBranch& Set(int offset, const QString &label);
        InstructionBranch& Set(BranchOperation operation,int offset,Register result,Register a1,const QString& label);
        int virtual Cycle(CoreState* coreState,InstructionState* instructionState);

        void SetOffset(int offset);
        int GetOffset();
};

class InstructionMemory : public Instruction
{
private:
    MemoryOperation operation;
public:
    virtual ~InstructionMemory(){}
    InstructionMemory& Set(MemoryOperation operation,Register result,Register argument,int offset);
    virtual InstructionState* GetNewState();
    virtual void CompleteRepresentation();
    virtual int Cycle(CoreState* coreState,InstructionState* instructionState);
};

class InstructionCache : public Instruction
{
public:
    virtual ~InstructionCache(){}
    InstructionCache();
    virtual InstructionState* GetNewState();
    virtual int Cycle(CoreState* coreState,InstructionState* instructionState);
};

class InstructionEnd : public Instruction
{
    public:
        InstructionEnd();
        virtual ~InstructionEnd(){}
        int virtual Cycle(CoreState* coreState,InstructionState* instructionState);
        InstructionState *GetNewState();
};

#endif // CONCRETEINSTRUCTIONS_H
