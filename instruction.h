#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "enums.h"
#include <QString>

class InstructionState;
class CoreState;

/**
 * @brief The abstract class from which all instructions derive.
 */
class Instruction
{
protected:

    /**
     * @brief The amount of cycles the system has to consume
     * in order to complete this instruction.
     */
    int cyclesCost;

    /**
     * @brief The text representation of this instruction.
     */
    QString representation;

    /**
     * @brief The register where the result of this instruction will be stored.
     * Optional
     */
    Register result;

    /**
     * @brief The register where the first argument of this instruction resides.
     * Optional
     */
    Register argument1;

    /**
     * @brief The register where the second argument of this instruction resides.
     * Optional
     */
    Register argument2;

    /**
     * @brief The imediate value argument this instruction has.
     * Optional
     */
    int imedValue;

protected:

    Instruction(int cyclesCost = 1);

    Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,Register argument2);

    Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,int imed);

    Instruction(int cyclesCost,const QString& representation,Register result,Register argument1,const QString& label);

    Instruction(int cyclesCost,const QString& representation);


    void Set(int cyclesCost,const QString& representation,Register result,Register argument1,Register argument2);

    void Set(int cyclesCost,const QString& representation,Register result,Register argument1,int imed);

    void Set(int cyclesCost,const QString& representation,Register result,Register argument1,const QString& label);

    void Set(int cyclesCost,const QString& representation);

public:

    /**
     * @brief Adds a label to this instruction.
     * @param label
     * @return
     */
    Instruction* AddLabel(const QString& label);

    virtual void CompleteRepresentation();

    virtual InstructionState* GetNewState();

    /**
     * @brief The main method of this class. This executes the logic of the instruction.
     * @param coreState
     * @param instructionState
     * @return The an offset for the Program Counter.
     * ex. 0 -> re executes the same instruction.
     *     1 -> Go to the next instruction.
     *    >1 -> Jumps to a different instruction.
     */
    int virtual Cycle(CoreState* coreState,InstructionState* instructionState) = 0;

    QString ToString();
};

#endif // INSTRUCTION_H
