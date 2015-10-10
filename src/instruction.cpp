#include "instruction.h"
#include "instructionState.h"

Instruction::Instruction(int cyclesCost)
{
    this->cyclesCost = cyclesCost;
}

Instruction::Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,Register argument2)
{
    Set(cyclesCost,representation,result,argument1,argument2);
}

Instruction::Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,int imed)
{
    Set(cyclesCost,representation,result,argument1,imed);
}

Instruction::Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,const QString& label)
{
   Set(cyclesCost,representation,result,argument1,label);
}

Instruction::Instruction(int cyclesCost,const QString& representation)
{
    Set(cyclesCost,representation);
}

void Instruction::Set(int cyclesCost,const QString& representation,Register result,Register argument1,Register argument2)
{
    this->cyclesCost = cyclesCost;
    this->representation = representation;
    this->result = result;
    this->argument1 = argument1;
    this->argument2 = argument2;

    CompleteRepresentation();
}

void Instruction::Set(int cyclesCost,const QString& representation,Register result,Register argument1,int imed)
{
    this->cyclesCost = cyclesCost;
    this->representation = representation;
    this->result = result;
    this->argument1 = argument1;
    this->argument2 = R_IMED;
    imedValue = imed;

    CompleteRepresentation();
}

void Instruction::Set(int cyclesCost,const QString& representation,Register result,Register argument1,const QString& label)
{
    this->cyclesCost = cyclesCost;
    this->representation = representation;
    this->result = result;
    this->argument1 = argument1;
    this->argument2 = R_NONE;

    CompleteRepresentation();
    this->representation +=   "," + label;
}

void Instruction::Set(int cyclesCost,const QString& representation)
{
    this->cyclesCost = cyclesCost;
    this->representation = representation;
    this->result = R_NONE;
    this->argument1 = R_NONE;
    this->argument2 = R_NONE;

    CompleteRepresentation();
}


Instruction* Instruction::AddLabel(const QString& label)
{
    this->representation = label + ": " + this->representation;
    return this;
}

void Instruction::CompleteRepresentation()
{
    if(result != R_NONE)
    {
        representation += RegisterNames[result] + ", " + RegisterNames[argument1];
    }

    if(argument2 != R_NONE)
    {
        representation += ((argument1 != R_NONE)? ", " : "") + RegisterNames[argument2];
    }

    representation = representation.replace("@",QString::number(imedValue));
}

InstructionState* Instruction::GetNewState()
{
    return new InstructionState(IS_Simple);
}

QString Instruction::ToString()
{
    return representation;
}
