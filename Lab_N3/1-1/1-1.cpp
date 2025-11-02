#include "Point.h"
#include <limits>


int main(){
    Point points[3] {};

    for (int i = 0; i < 3; i++){
        std::cout << "Enter cordinates of point " << i+1 << ": ";
        double x {}, y {};
        while (true){
            if (std::cin >> x >> y){
                break;
            }
            else{
                std::cout << "Invalid input. Input valid values." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        points[i] = Point(x,y);
    }
    for (int j = 0; j < 3; j++){
        std::cout << "Cordinates of point " << j + 1 << " are: ";
        points[j].cordinates();
    }
}