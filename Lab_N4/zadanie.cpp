#include "LineSegment.h"
#include <limits>

int main()
{
    double begin,end;
    std::cout << "Enter points of begin and end:" << std::endl;
    while (true){
        if (std::cin >> begin >> end){
            break;
        }
        else{
            std::cout << "Invalid input. Input valid values" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    LineSegment lineSegment(begin,end);
    double point;
    std::cout << "Enter number to check if it's included in line segment:" << std::endl;
    while (true){
        if (std::cin >> point){
            break;
        }
        else{
            std::cout << "Invalid input. Inpud valid values" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    if (lineSegment.Include(point))
    {
        std::cout << "Point is included" << std::endl;
    }
    else{
        std::cout << "Point isn't included" << std::endl;
    }
    std::cout << "Lenght of line segment: " << !lineSegment << std::endl;
    ++lineSegment;
    std::cout << "Line segment after increment: ";
    lineSegment.print();
    int x = static_cast<int>(lineSegment);
    std::cout << "Change type to int :" <<  x << std::endl;
    double y = lineSegment;
    std::cout << "Change type to double: "<<  y << std::endl;
    LineSegment newLineSegment = lineSegment + 5;
    std::cout << "Line segment after adding 5: ";
    newLineSegment.print();
    if (lineSegment > 5)
        {
            std::cout << "OK" << std::endl;
        }
    else
        {
            std::cout << "NOT OK" << std::endl;
        }
}