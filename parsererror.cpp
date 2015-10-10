#include "parsererror.h"
#include "enums.h"

ParserError::ParserError(ParsingErrorCode errorCode, const QString &errorString,int line):errorCode(errorCode),errorString(errorString),line(line)
{
}

QString ParserError::what()
{
    QString what = "* ";
    what += ParsingErrorMessages[(int)errorCode];
    what += " ";
    what += errorString;
    what += QString(" at line : ");
    what += QString::number(line + 1);//lines are not zero based on files
    return what;
}
