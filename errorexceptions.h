#ifndef ERROREXCEPTIONS_H
#define ERROREXCEPTIONS_H
#include<string>
#include <QString>
using std::string;
class ErrorExceptions
{
public:
    ErrorExceptions(QString);
    QString geterror() const;
private:
    QString error;
};

#endif // ERROREXCEPTIONS_H
