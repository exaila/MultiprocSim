#ifndef PARSERERROR_H
#define PARSERERROR_H

#include <QString>
#include "enums.h"

class ParserError
{
private:
    ParsingErrorCode errorCode;
    QString errorString;
    int line;
public:
    ParserError(ParsingErrorCode errorCode,const QString& errorString,int line);
    QString what();
};

#endif // PARSERERROR_H
