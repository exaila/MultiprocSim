#include "concreteInstructions.h"
#include "coreState.h"
#include "instructionState.h"
#include "cachemapper.h"
#include "enums.h"

InstructionLoadImed::InstructionLoadImed(Register result,int value):Instruction(1,"li ",result,R_NONE,value)
{

}

int InstructionLoadImed::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    coreState->Set(result, imedValue );
    return instructionState->Cylce(cyclesCost);
}

/*Arithmatic*/
InstructionArithmetic& InstructionArithmetic::Set(ArithmeticOperation operation,Register result,Register a1,Register a2)
{
    this->operation = operation;
    QString name = AritmeticInstructionNames[operation];
    Instruction::Set(1,name + " ",result,a1,a2);
    return *this;
}

InstructionArithmetic& InstructionArithmetic::Set(ArithmeticOperation operation,Register result,Register a1,int a2)
{
    this->operation = operation;
    QString name = AritmeticInstructionNames[operation] + 'i';
    Instruction::Set(1,name + " ",result,a1,a2);
    return *this;
}

int InstructionArithmetic::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    if(argument2 != R_IMED)
    {
        imedValue = coreState->Get(argument2);
    }

    switch(operation)
    {
        case ArithmeticOperationAdd:
            coreState->Set(result, coreState->Get(argument1) + imedValue );
        break;
        case ArithmeticOperationSub:
            coreState->Set(result, coreState->Get(argument1) - imedValue );
        break;
        case ArithmeticOperationMult:
            coreState->Set(result, coreState->Get(argument1) * imedValue );
        break;
        case ArithmeticOperationDiv:
            coreState->Set(result, coreState->Get(argument1) / imedValue );
        break;
    }

    return instructionState->Cylce(cyclesCost);
}

InstructionBranch& InstructionBranch::Set(int offset,const QString& label)
{
    this->imedValue = offset;
    this->operation = BranchOperationJump;
    Instruction::Set(1,"j " + label);
    return *this;
}

InstructionBranch& InstructionBranch::Set(BranchOperation operation,int offset,Register result,Register a1,const QString& label)
{
    this->operation = operation;
    this->imedValue = offset;
    Instruction::Set(1,BranchInstructionNames[operation]  + " ",result,a1,label);
    return *this;
}

int InstructionBranch::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    if(instructionState->Cylce(cyclesCost))
    {
        if(operation == BranchOperationJump)
        {
            return imedValue;
        }
        else
        {
            int data1 = coreState->Get(result);
            int data2 = coreState->Get(argument1);

            if( (data1 == data2 && operation == BranchOperationBranchEqual)
                    || (data1 != data2 && operation == BranchOperationBranchNotEqual))
            {
                return imedValue;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}

void InstructionBranch::SetOffset(int offset)
{
    this->imedValue = offset;
}

int InstructionBranch::GetOffset()
{
    return imedValue;
}

InstructionMemory &InstructionMemory::Set(MemoryOperation operation, Register result, Register argument, int offset)
{
    this->operation = operation;

    Instruction::Set(0,"",result,argument,offset);

    CompleteRepresentation();
    return *this;
}

InstructionState* InstructionMemory::GetNewState()
{
    return new InstructionState(IS_Cache);
}

void InstructionMemory::CompleteRepresentation()
{
    representation = MemoryInstructionNames[(int)operation] +
            " " + RegisterNames[(int)result] + ", "+ QString::number(imedValue) +
            "(" + RegisterNames[(int)argument1] + ")";
}

int InstructionMemory::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    if(operation == MemoryOperationStoreByte)
    {
        instructionState->Cylce(coreState->GetCacheMapper()->GetRamCost());
        return coreState->MemoryWrite(instructionState,argument1,result,imedValue);
    }
    else if(operation == MemoryOperationLoadByte)
    {
        instructionState->Cylce(((instructionState->Stage() == IS_Ram) ? coreState->GetCacheMapper()->GetRamCost() : coreState->GetCacheMapper()->GetCacheCost()));
        return coreState->MemoryRead(instructionState,argument1,result,imedValue);
    }
    return 0;
}

/*Cache*/
InstructionCache::InstructionCache():Instruction(0,"cache")
{
}

int InstructionCache::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    if(instructionState->Cylce(coreState->GetCacheMapper()->GetCacheCost()))
    {
        coreState->InvalidateCache();
        return 1;
    }
    return 0;
}

InstructionState* InstructionCache::GetNewState()
{
    return new InstructionState(IS_Cache);
}

/*End*/
InstructionEnd::InstructionEnd():Instruction(1,"program end" )
{

}

InstructionState* InstructionEnd::GetNewState()
{
    return new InstructionState(IS_ProgramEnd);
}

int InstructionEnd::Cycle(CoreState* coreState,InstructionState* instructionState)
{
    return 0;
}
