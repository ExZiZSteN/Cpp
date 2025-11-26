#pragma once
#include <iostream>

class LineSegment{
    private:
        double x_;
        double y_;
    public:
        LineSegment() : x_(0), y_(0) {};
        LineSegment(double x, double y) : x_(x),y_(y) {};
        LineSegment(double x): x_(x),y_(x){};
        void print(){
            std::cout << "[" << x_ << ";" <<  y_ << "]" << std::endl;
        }
        bool Include(double x);
        friend std::ostream& operator<< (std::ostream& out, const LineSegment& lineSegment);
        double operator!();
        LineSegment& operator++();
        explicit operator int() const;
        operator double() const;
        bool operator> (const int& value);
        LineSegment operator+ (const int& value);
    };

