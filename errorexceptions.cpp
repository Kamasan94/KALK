#include "errorexceptions.h"

ErrorExceptions::ErrorExceptions(QString t) : error(t) {}
QString ErrorExceptions::geterror() const { return error; }
