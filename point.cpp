#include "point.h"

Point::Point(double x, double y) : xval(x), yval(y){}

double Point::getx() const{ return xval;}
double Point::gety() const{ return yval;}

double Point::dist(const Point& p) const{
    double xd = xval - p.xval;
    double yd = yval - p.yval;
    return sqrt(xd*xd +yd*yd);
}
Point Point::operator + (const Point& p){
    return Point(xval + p.xval, yval+p.yval);
}
Point Point::operator - (const Point& p ){
    return Point(xval - p.xval, yval - p.yval);
}
Point Point::operator * (const Point& p){
    return Point(xval * p.xval, yval * p.yval);
}
Point Point::operator / (const Point& p){
    return Point(xval / p.xval, yval * p.yval);
}
bool Point::operator == (const Point& p) {
    return xval == p.xval && yval == p.yval;
}

void Point::move(double a, double b){
    xval += a;
    yval += b;
}

Point Point::operator*=(double c) {
    return Point(xval*c,yval*c);
}

Point Point::operator^(double c) {
    return Point(pow(xval,c), pow(yval,c));
}

void Point::setx(double c)  { xval = c; }
void Point::sety(double c)  { yval = c; }
