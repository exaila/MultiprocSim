#ifndef INSTRUCTIONSTATE_H
#define INSTRUCTIONSTATE_H

#include "enums.h"

/**
 * @brief The state of an instruction.
 * This includes information about the current stage of the instruction (read from L2 or L1 cache, blocked etc.)
 * the total amount of cycles spent etc.
 */
class InstructionState
{
private:

    InstructionStage stage;

    bool completed;

    int cyclesSpent;

    int cycleCost;

    //unused
    PipelineState pipelineState;

public:

    InstructionState(InstructionStage stage);

    int CyclesSpent() const;

    bool Cylce(int cycleCost);

    InstructionStage Stage() const;

    void SetStage(InstructionStage stage);

    int IsCompleted() const;

    /**
     * @brief Declare this instruction as completed.
     */
    void Complete();
};

#endif // INSTRUCTIONSTATE_H
