#ifndef PARSER_H
#define PARSER_H

#include <QMap>
#include <QFile>
#include <QVector>
#include <QPair>
#include "enums.h"

class CodeList;
class Instruction;
class InstructionArithmetic;
class InstructionBranch;
class InstructionMemory;
class ParserError;

/**
 * @brief The Parser class parses a code file
 * and produces a code list or a list of parsing errors.
 */
class Parser
{
private:

    /**
     * @brief A map used to hold the line number of each label.
     * Used to calculate the offset of branch instructions.
     */
    QMap<QString,int> labelResolution;

    /**
     * @brief A vector with all branch instruction found during parsing.
     * After the parsing is complete, and all possible labels were found
     * this vector is used to resolve them (replace all label strings with the coresponding offsets).
     */
    QVector<QPair<InstructionBranch*,QString> > toBeResolved;

    /**
     * @brief All errors produced by the parser are stored here.
     */
    QVector<ParserError*> errors;

    /**
     * @brief Parses a sungle line (instruction) and returns the generated instruction.
     * @param line
     * @param lineNumber
     * @param ok
     * @return
     */
    Instruction* ParseSingleLine(QString &line, int lineNumber, bool &ok);

    /**
     * @brief Calculates all the offsets for the instructions in the toBeResolved vector.
     * Called at the end of the parsing. (we need to have all labels in palce to resolve them.)
     */
    bool ResolveLabels();

    /**
     * @brief Returns the label of the given line.
     * @param line
     * @param lineNumber
     * @return
     */
    QString GetLabel(const QString &line, int lineNumber);

    /**
     * @brief Returns true if the given line has a label.
     * @param line
     * @return
     */
    bool HasLabel(const QString &line);

    /**
     * @brief Returns the offset for the branch instruction in currentLine
     * which jumps to the given label.
     * @param label
     * @param currentLine
     * @return
     */
    int DereferenceLabelOffset(const QString &label, int currentLine, bool &ok);

    /**
     * @brief Returns the enum code of the given register.
     * @param registerName
     * @param ok If no register was found with thegiven name this will be false.
     * @return
     */
    Register ParseRegisterName(const QString &registerName, bool &ok);

    Instruction* CreateInstruction(QStringList &args,int currentLine);

    InstructionArithmetic* ParseArithmeticOperation(ArithmeticOperation operation, QStringList &args, int currentLine);

    InstructionBranch* ParseBranchOperation(BranchOperation operation, QStringList &args, int currentLine);

    InstructionMemory *ParseMemoryOperation(MemoryOperation operation,QStringList& args, int currentLine);

    Instruction* ParseLoadImedOperation(QStringList &args,int currentLine);
public:

    Parser();

    /**
     * @brief Parse the given codefile and fill the given code list with instructions.
     * @param fileName
     * @param codeList
     * @return False in case of an error.
     */
    ParsingErrorCode Parse(const QString &fileName, CodeList& codeList);

    QVector<ParserError *> getErrors() const;
};

#endif // PARSER_H
