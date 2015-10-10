#include "parser.h"
#include "instruction.h"
#include "concreteInstructions.h"
#include "helper.h"
#include "codelist.h"
#include "parsererror.h"

#include <QStringList>

Parser::Parser()
{
}

ParsingErrorCode Parser::Parse(const QString& fileName, CodeList& codeList)
{
    //open file
    QFile file(fileName);
    file.open(QFile::ReadOnly);

    //buffer for reading each line
    char data[80];

    bool ok = true;
    
    int lineNumber = 0;
    
    while(!file.atEnd())
    {
        //get the line
        if(file.readLine(data,80) == -1)
        {
            ok = false;
            errors << new ParserError(Parsing_ERROR_FileError,data,0);
            break;
        }

        QString line(data);

        //simplify the whitespaces
        line = line.simplified().toLower();

        //remove comments
        line.remove(QRegExp("#.*"));

        //remove starting and tailing whitespaces
        Trim(line);

        if(!line.isSimpleText())
        {
            ok = false;
            errors << new ParserError(Parsing_ERROR_FileError,data,0);
            break;
        }

        //if valid
        if(!line.isEmpty())
        {            
            Instruction* instruction = ParseSingleLine(line,lineNumber,ok);

            //if a valid instruction was parsed add it
            if(instruction != NULL)
            {
                codeList << instruction;
                lineNumber++;
            }
            else
            {
                //in case of too many errors
                if(errors.length() > 10)
                {
                    break;
                }
            }
        }
    }
    
    file.close();

    if(!ok)
    {
        codeList.Clear();
        return Parsing_ERROR;
    }

    codeList << new InstructionEnd;

    if(!ResolveLabels())
    {
        codeList.Clear();
        return Parsing_ERROR_UnresolvedLabel;
    }

    return Parsing_OK;
}


QVector<ParserError *> Parser::getErrors() const
{
    return errors;
}

Instruction *Parser::ParseSingleLine(QString& line,int lineNumber,bool& ok)
{
    QString label;
    Instruction* instruction = NULL;

    //Try to parse label first, if any
    if(HasLabel(line))
    {
        label = GetLabel(line,lineNumber);

        //FIXME: TEMP HACK
        line.remove(label + ":");
        Trim(line);
    }

    //break line to each arguments
    QStringList args = line.split(QRegExp("[ ,()]"),QString::SkipEmptyParts);
    if(args.count() != 0)
    {
        instruction = CreateInstruction(args,lineNumber);

        if(instruction != NULL)
        {
            ok &= true;

            //add label if any
            if(!label.isEmpty())
            {
                instruction->AddLabel(label);
            }
        }
        else
        {
            ok = false;
        }
    }

    return instruction;
}

bool Parser::ResolveLabels()
{
    bool ok = true;
    const int count = toBeResolved.size();

    for(int i = 0; i < count;i++ )
    {
        int line = toBeResolved[i].first->GetOffset();
        int offset = DereferenceLabelOffset(toBeResolved[i].second,line,ok);

        toBeResolved[i].first->SetOffset(offset);
    }

    return ok;
}

bool Parser::HasLabel(const QString& line)
{
    return line.contains(":");
}

QString Parser::GetLabel(const QString& line,int lineNumber)
{
    QStringList args = line.split(':',QString::SkipEmptyParts);

    if(args.count() == 2)
    {
        labelResolution[args[0]] = lineNumber;
        return args[0];
    }
    else
    {
        //error
        //errors << new ParserError(Parsing_ERROR_InvalidNumberOfArguments,QString::number(args.length()),-1);
        return "";
    }
}

Instruction* Parser::CreateInstruction(QStringList& args,int currentLine)
{
    Instruction* instruction = NULL;
    int index;

    if(args[0] == "li")
    {
        instruction = ParseLoadImedOperation(args,currentLine);
    }
    else if(Contains(AritmeticInstructionNames,0,(int)ArithmeticOperationTotal,args[0],index))
    {
        instruction = ParseArithmeticOperation((ArithmeticOperation)index,args,currentLine);
    }
    else if(Contains(BranchInstructionNames,0,(int)BranchOperationTotal,args[0],index))
    {
        instruction = ParseBranchOperation((BranchOperation)index,args,currentLine);
    }
    else if(Contains(MemoryInstructionNames,0,(int)MemoryOperationTotal,args[0],index))
    {
        instruction = ParseMemoryOperation((MemoryOperation)index,args,currentLine);
    }
    else if(args[0] == "cache")
    {
        instruction = new InstructionCache;
    }
    else
    {
        //error instruction not supported
    }
    return instruction;
}

InstructionMemory* Parser::ParseMemoryOperation(MemoryOperation operation,QStringList& args,int currentLine)
{
    if(args.length() != 4)
    {
        //error wrong arguments
        errors << new ParserError(Parsing_ERROR_InvalidNumberOfArguments,QString::number(args.length()),currentLine);
        return NULL;
    }

    bool ok = true;

    InstructionMemory* instruction = new InstructionMemory;

    Register result = ParseRegisterName(args[1],ok);
    int offset = args[2].toInt(&ok,10);
    Register argument = ParseRegisterName(args[3],ok);

    if(ok)
    {
        instruction->Set(operation,result,argument,offset);
    }
    else
    {
        errors << new ParserError(Parsing_ERROR_InvalidNumberOfArguments,QString::number(args.length()),currentLine);
        delete instruction;
        instruction = NULL;
    }

    return instruction;
}

Instruction *Parser::ParseLoadImedOperation(QStringList &args, int currentLine)
{
    if(args.length() != 3)
    {
        //error
        errors << new ParserError(Parsing_ERROR_InvalidNumberOfArguments, QString::number( args.length()),currentLine);
        return NULL;
    }

    bool ok = true;

    Register result = ParseRegisterName(args[1],ok);
    if(!ok)
    {
        //error
        errors << new ParserError(Parsing_ERROR_InvalidRegisterName,args[1],currentLine);
        return NULL;
    }

    int imedValue = args[2].toInt(&ok,10);
    if(!ok)
    {
        //error
        errors << new ParserError(Parsing_ERROR_InvalidArgumentValue,args[2],currentLine);
        return NULL;
    }

    return new InstructionLoadImed(result,imedValue);
}

InstructionArithmetic* Parser::ParseArithmeticOperation(ArithmeticOperation operation,QStringList& args,int currentLine)
{
    if(args.length() != 4)
    {
        //error
        errors << new ParserError(Parsing_ERROR_InvalidNumberOfArguments, QString::number( args.length()),currentLine);
        return NULL;
    }

    bool ok = true;

    Register result = ParseRegisterName(args[1],ok);
    Register argument1 = ParseRegisterName(args[2],ok);

    if(!ok)
    {
        //error
        errors << new ParserError(Parsing_ERROR_InvalidRegisterName,args[2],currentLine);
        return NULL;
    }

    InstructionArithmetic* instruction = new InstructionArithmetic;
    Register argument2 = ParseRegisterName(args[3],ok);

    if(ok)
    {
        instruction->Set(operation,result,argument1,argument2);
    }
    else//probably an imediate value
    {
        int argument2Imed = args[3].toInt(&ok,10);
        if(ok)
        {
            instruction->Set(operation,result,argument1,argument2Imed);
        }
        else
        {
            //error
            errors << new ParserError(Parsing_ERROR_InvalidArgumentValue,args[3],currentLine);

            delete instruction;
            instruction = NULL;
        }
    }

    return instruction;
}

InstructionBranch* Parser::ParseBranchOperation(BranchOperation operation,QStringList& args,int currentLine)
{
    bool ok = true;
    QString label;
    InstructionBranch* instruction = new InstructionBranch;

    //we can't (probably) resolve yet the label
    //thus we set the offset for the instruction as the current line
    //and add the instruction to a vector to resolve it later.
    if(operation == BranchOperationJump)
    {
        label = args[1];
        instruction->Set(currentLine,label);
    }
    else
    {
        Register result = ParseRegisterName(args[1],ok);
        Register argument1 = ParseRegisterName(args[2],ok);

        label = args[3];
        instruction->Set(operation,currentLine,result,argument1,label);
    }

    toBeResolved << QPair<InstructionBranch*,QString>(instruction,label);

    return instruction;
}

Register Parser::ParseRegisterName(const QString& registerName,bool& ok)
{
    int index = 0;
    //skip the first two names while searching for the register name
    ok &= Contains(RegisterNames,2,R_Total,registerName,index);

    return (Register)index;
}

int Parser::DereferenceLabelOffset(const QString& label,int currentLine,bool& ok)
{
    if(labelResolution.contains(label))
    {
        ok &= true;
        return labelResolution[label] - currentLine;
    }
    else
    {
        //error unresovled label
        errors << new ParserError(Parsing_ERROR_UnresolvedLabel,label,currentLine);

        ok = false;
        return 0;
    }
}
