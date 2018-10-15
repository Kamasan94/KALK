#ifndef POINT_H
#define POINT_H
#include<math.h>

class Point {
private:
    double xval;
    double yval;
public:
    Point(double = 0.0, double = 0.0);
    double getx() const;
    double gety() const;

    double dist(const Point&) const;
    Point operator + (const Point&);
    Point operator - (const Point&);
    Point operator * (const Point&);
    Point operator / (const Point&);
    bool operator == (const Point&);
    Point operator *= (double);
    Point operator ^ (double);
    void setx(double);
    void sety(double);
    void move(double, double);

};


#endif // POINT_H
