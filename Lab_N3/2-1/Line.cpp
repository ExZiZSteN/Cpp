#include "Line.h"


void Point::cordinates(){
    std::cout << "{"<< x_ << ";" << y_ << "}" ;
}

void Line::LineCordinates(){
        std::cout << "Line from ";
        start_.cordinates();
        std::cout << " to ";
        end_.cordinates();
        std::cout << std::endl;
    }