#include "codelist.h"
#include "concreteInstructions.h"
#include "helper.h"

#include <QStandardItem>

CodeList::CodeList():model(NULL),highlightedIndex(-1)
{
}

CodeList::~CodeList()
{
    if(model)
    {
        model->clear();
        delete model;
    }
}

QStandardItemModel *CodeList::GetModel()
{
    if(model == NULL)
    {
        model = new QStandardItemModel;
        for (int i = 0; i < instructions.count(); i++)
        {
            QStandardItem* data = new QStandardItem(instructions[i]->ToString());
            data->setFlags(0);
            model->setItem(i, 0, data);
            //model->setItem(i, 1, new QStandardItem(QString("")));
        }
    }

    return model;
}

Instruction *CodeList::Get(int index)
{
    return instructions[index];
}

void CodeList::Clear()
{
    instructions.clear();
}

CodeList *CodeList::CreateSingleCodeList()
{
    CodeList* codeList = new CodeList();

    codeList->instructions
                           << new InstructionLoadImed(R_S1,10)
                          /* << new InstructionLoadImed(R_T1,startAddress)//la
                           << (new InstructionBranch(BranchOperationBranchEqual,6,R_S1,R_T0,"EndLoop"))->AddLabel("Loop")
                           << new InstructionLoadByte(R_T2,R_T1)
                           << new InstructionArithmetic(R_S0,R_S0,R_T2)
                           << new InstructionArithmetic(R_T1,R_T1,1)
                           << new InstructionArithmetic(R_T0,R_T0,1)
                           << new InstructionBranch(-5,"Loop")
                           << (new InstructionLoadImed(R_T1,63))->AddLabel("EndLoop")
                           << new InstructionStore(R_S0,R_T1)*/
                           << new InstructionEnd;
    return codeList;
}

CodeList *CodeList::CreateFirstCodeList()
{
    CodeList* codeList = new CodeList();

    codeList->instructions
                           << new InstructionLoadImed(R_S1,10)
                         /*  << new InstructionLoadImed(R_T1,startAddress)//la
                           <<(new InstructionBranch(BranchOperationBranchEqual,6,R_S1,R_T0,"EndLoop1"))->AddLabel("Loop1")
                           << new InstructionLoadByte(R_T2,R_T1)
                           << new InstructionArithmetic(R_S0,R_S0,R_T2)
                           << new InstructionArithmetic(R_T1,R_T1,1)
                           << new InstructionArithmetic(R_T0,R_T0,1)
                           << new InstructionBranch(-5,"Loop1")
                           << (new InstructionLoadImed(R_T0,1))->AddLabel("EndLoop1")
                           << new InstructionLoadImed(R_T1,62)//la
                           << (new InstructionCache(10))->AddLabel("Loop2")
                           << new InstructionLoadByte(R_T2,R_T1)
                           << new InstructionBranch(BranchOperationBranchNotEqual,-2,R_T2,R_T0,"Loop2")
                           << new InstructionLoadImed(R_T1,63)//la
                           << new InstructionLoadByte(R_T2,R_T1)
                           << new InstructionArithmetic(R_S0,R_S0,R_T2)
                           << new InstructionStore(R_S0,R_ZERO)*/
                           << new InstructionEnd;
    return codeList;
}

CodeList *CodeList::CreateSecondCodeList()
{
    CodeList* codeList = new CodeList();

    codeList->instructions
                           << new InstructionLoadImed(R_S1,10)
                          /* << new InstructionLoadImed(R_T1,startAddress)//la
                           << (new InstructionBranch(6,R_S1,R_T0,"EndLoop"))->AddLabel("Loop")
                           << new InstructionLoadByte(R_T2,R_T1)
                           << new InstructionArithmetic(R_S0,R_S0,R_T2)
                           << new InstructionArithmetic(R_T1,R_T1,1)
                           << new InstructionArithmetic(R_T0,R_T0,1)
                           << new InstructionBranch(-5,"Loop")
                           << (new InstructionLoadImed(R_T1,63))->AddLabel("EndLoop")
                           << new InstructionStore(R_S0,R_T1)
                           << new InstructionLoadImed(R_T1,62)
                           << new InstructionLoadImed(R_T0,1)
                           << new InstructionStore(R_T0,R_T1)*/
                           << new InstructionEnd();
    return codeList;
}

CodeList &CodeList::operator <<(Instruction *instruction)
{
    this->instructions << instruction;
    return *this;
}

void CodeList::HighlightInstuction(int index)
{
    if(highlightedIndex != -1)
    {
        HighlightSingleRow(model,highlightedIndex,QColor(255,255,255));
    }
    HighlightSingleRow(model,index,QColor(150,200,150));
    highlightedIndex = index;
}

