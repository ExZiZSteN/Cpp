#include "LineSegment.h"

bool LineSegment::Include(double x)
{
    return x_ <= x && x <= y_;
}

std::ostream& operator<< (std::ostream& out, const LineSegment& lineSegment)
{
    out << "[" << lineSegment.x_ << "; " << lineSegment.y_ << ")";
    return out;
}

double LineSegment::operator!() {
    return y_ - x_;
}

LineSegment& LineSegment::operator++(){
    x_ = x_  + 1;
    y_ = y_ + 1;
    return *this;
}

LineSegment::operator int() const{
    return int(x_);
}

LineSegment::operator double() const{
    return y_;
}

LineSegment LineSegment::operator+ (const int& value){
    return LineSegment(x_ + value, y_ + value);
}

bool LineSegment::operator> (const int& value){
    return Include(value);
}