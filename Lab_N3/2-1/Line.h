#pragma once
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

class Line
{
private:
    Point start_ {};
    Point end_ {};
public:
    Line(Point start = Point(), Point end = Point()){
        start_ = start;
        end_ = end;
    };
    void LineCordinates();
};