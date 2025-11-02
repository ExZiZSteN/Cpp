#include "Line.h"
#include <limits>

void InputCordinates(Point& start, Point& end){
    for (int i = 0; i < 2; i++){
        while (true){
            double x{}, y{};
            if (i == 0){
                std::cout << "Enter start point cordinates (x,y):" << std::endl;
                if (std::cin >> x >> y){
                    start = Point(x,y);
                    break;
                }
                else{
                    std:: cout << "Invalid input. Input valid values" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                };
            }
            else{
                std::cout << "Enter end point cordinates (x,y):" << std::endl;
                if (std::cin >> x >> y){
                    end = Point(x,y);
                    break;
                }
                else{
                    std:: cout << "Invalid input. Input valid values" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            };
        };
    };
}


int main()
{
    Point start1(1,3);
    Point end1(23,8);
    Line line1(start1,end1);
    std::cout << "Frist line cordinates: " << std::endl;
    line1.LineCordinates();
    Point start2(5,10);
    Point end2(25,0);
    Line line2(start2,end2);
    std::cout << "Second line cordinates: " << std::endl;
    line2.LineCordinates();
    Line line3(start1,end2);
    std::cout << "Third line cordinates: " << std::endl;
    line3.LineCordinates();
    std:: cout << "Change cordinates of firts line:" << std::endl;
    InputCordinates(start1, end1);
    line1 = Line(start1,end1);
    std::cout << "Change cordinates of second line:" << std::endl;
    InputCordinates(start2, end2);
    line2 = Line(start2,end2);
    line1.LineCordinates();    
    line2.LineCordinates();
    line3 = Line(start1,end2);
    line3.LineCordinates();
    std:: cout << "Change cordinates of firts line:" << std::endl;
    InputCordinates(start1, end1);
    line1 = Line(start1,end1);
    line1.LineCordinates();
}