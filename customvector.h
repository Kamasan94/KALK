#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H
#include<vector>
#include "point.h"
#include "errorexceptions.h"
using std::vector;

class CustomVector : public Point
{
public:
    CustomVector(int = 0);
    CustomVector operator + (CustomVector&);
    CustomVector operator - (CustomVector&);
    CustomVector operator / (CustomVector&);
    CustomVector operator * (CustomVector&);
    CustomVector operator *=(double);
    CustomVector operator ^ (double);
    void setElement(double, int);
    int getSize() const;
    double getVal(int) const;
    CustomVector ex(CustomVector&, int);
private:
    vector<double> vec;
    int size;
};

#endif // CUSTOMVECTOR_H
