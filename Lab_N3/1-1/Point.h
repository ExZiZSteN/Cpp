#ifndef Point_h
#define Point_h

#include <iostream>

class Point
{
private:
    double x_ {};
    double y_ {};
public:
    Point(double x = 0, double y = 0){
        x_= x;
        y_ = y;
    };

    void cordinates();
};



#endif