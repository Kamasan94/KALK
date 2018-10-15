#include "customvector.h"

CustomVector::CustomVector(int s) : size(s) {
    for(int i=0; i<s; i++) {
        vec.push_back(0);
    }
    Point(0,0);
}



CustomVector CustomVector::operator+(CustomVector& v) {
    if(size != v.size)
        throw(ErrorExceptions("I vettori devono avere dimensioni uguali"));
    CustomVector temp(size);
    for(int i=0; i<size; i++){
        temp.vec[i] = vec[i] + v.vec[i];
    }
    return temp;
}

CustomVector CustomVector::operator-(CustomVector& v) {
    if(size != v.size)
        throw(ErrorExceptions("I vettori devono avere dimensioni uguali"));
    CustomVector temp(size);
    for(int i=0; i<size; i++){
        temp.vec[i] = vec[i] - v.vec[i];
    }
    return temp;
}

CustomVector CustomVector::operator*(CustomVector& v) {
    if(size != v.size)
        throw(ErrorExceptions("I vettori devono avere dimensioni uguali"));
    CustomVector temp(size);
    for(int i=0; i<size; i++){
        temp.vec[i] += vec[i] * v.vec[i];
    }
    return temp;
}

CustomVector CustomVector::operator*=(double v) {
    CustomVector temp(size);
    for(int i=0; i<size; i++){
        temp.vec[i] = vec[i] * v;
    }
    return temp;
}

CustomVector CustomVector::operator^(double v) {
    CustomVector temp(*this);
    return ex(temp,v);
}
CustomVector CustomVector::ex(CustomVector& m, int num){
    if (num == 0) {
        for(int i =0; i<m.size; i++)
            m.vec[i] = 0;
        return m;
        }
    else if (num == 1) {
        return m;
    }
    else{
        for(int i = 0; i<m.getSize(); i++){
            m.vec[i] = pow(vec[i],num);
        }

    }
    return m;

}

void CustomVector::setElement(double c, int i) {
    vec[i] = c;
}

int CustomVector::getSize() const { return vec.size(); }

double CustomVector::getVal(int i) const { return vec[i]; }
