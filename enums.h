#ifndef ENUMS_H
#define ENUMS_H

#include <QString>

/**
  * A centralized file with all enums and their string equivalents.
  * This file is obsolete with the use of C++11.
  */

/**
 * The registers used by the simulation.
 */
enum Register
{
    R_NONE,
    R_IMED,
    R_ZERO,
    R_T0,
    R_T1,
    R_T2,
    R_T3,
    R_T4,
    R_T5,
    R_T6,
    R_S0,
    R_S1,
    R_S2,
    R_S3,
    R_S4,
    R_S5,
    R_S6,
    R_Total
};

enum InstructionStage
{
    IS_Simple,
    IS_Ram,
    IS_Blocked,
    IS_Cache,
    IS_ProgramEnd
};

enum PipelineState
{
    PS_LoadInstruction,
    PS_Total
};

/**
 * The name of each register.
 */
const QString RegisterNames[] = {"","@","$0","$t0","$t1","$t2","$t3","$t4","$t5","$t6","$s0","$s1","$s2","$s3","$s4","$s5","$s6"};


enum ArithmeticOperation
{
    ArithmeticOperationAdd,
    ArithmeticOperationSub,
    ArithmeticOperationDiv,
    ArithmeticOperationMult,
    ArithmeticOperationTotal
};

const QString AritmeticInstructionNames[] = {"add","sub","mul","div"};

enum BranchOperation
{
    BranchOperationJump,
    BranchOperationBranchEqual,
    BranchOperationBranchNotEqual,
    BranchOperationTotal
};

const QString BranchInstructionNames[] = {"j","beq","bne"};

enum MemoryOperation
{
    MemoryOperationLoadByte,
    MemoryOperationStoreByte,
    MemoryOperationTotal
};

const QString MemoryInstructionNames[] = {"lb","sb"};


enum ParsingErrorCode
{
    Parsing_OK = 0,
    Parsing_ERROR,
    Parsing_ERROR_InvalidInstructionName,
    Parsing_ERROR_InvalidRegisterName,
    Parsing_ERROR_InvalidArgumentValue,
    Parsing_ERROR_UnresolvedLabel,
    Parsing_ERROR_InvalidNumberOfArguments,
    Parsing_ERROR_FileError,
    Parsing_ERROR_TOTAL
};

const QString ParsingErrorMessages[] = 
{
    "ok",
    "Parsing Error",
    "Invalid Instruction Name",
    "Invalid Register Name",
    "Invalid Argument Value",
    "Unresolved Label",
    "Invalid Number Of Arguments",
    "File Read Error",
    "inv"
};

#endif // ENUMS_H
