#ifndef CODELIST_H
#define CODELIST_H

#include <QVector>
#include "instruction.h"

class QStandardItemModel;

class CodeList
{
private:

    QVector<Instruction*> instructions;

    QStandardItemModel* model;

    int highlightedIndex;

public:

    CodeList();

    virtual ~CodeList();

    //used to create a CodeList for the first core
    // OBSOLETE
    static CodeList* CreateFirstCodeList();

    //used to create a CodeList for the second core
    // OBSOLETE
    static CodeList* CreateSecondCodeList();

    /**
     * used to create a CodeList for a single core
     * OBSOLETE
     */
    static CodeList* CreateSingleCodeList();

    /**
     * @brief operator << Appends a new instruction to this codelist.
     * @param instruction
     * @return
     */
    CodeList& operator <<(Instruction* instruction);

    /**
     * @brief Highlights the given instruction.
     * @param index
     */
    void HighlightInstuction(int index);

    QStandardItemModel* GetModel();

    Instruction* Get(int index);

    void Clear();
};

#endif // CODELIST_H
