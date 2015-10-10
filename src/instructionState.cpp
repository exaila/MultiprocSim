#include "instructionState.h"

InstructionState::InstructionState(InstructionStage stage):stage(stage),completed(false),cyclesSpent(0)
{

}

int InstructionState::CyclesSpent() const
{
    return cyclesSpent;
}

bool InstructionState::Cylce(int cycleCost)
{
    cyclesSpent++;
    if(cycleCost <= cyclesSpent)
    {
        Complete();
        return true;
    }
    return false;
}

InstructionStage InstructionState::Stage() const
{
    return stage;
}

void InstructionState::SetStage(InstructionStage stage)
{
    this->stage = stage;
    cyclesSpent = 0;
}

int InstructionState::IsCompleted() const
{
    return completed ? 1 : 0;
}

void InstructionState::Complete()
{
    completed = true;
}
