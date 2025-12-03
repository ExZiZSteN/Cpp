#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
#include "Laba5.h"

int main()
{   

    makeFile("numbers.txt");
    int b;
    std::cout << "Enter number to find: ";
    while (true){
        if (std::cin >> b){
            break;
        }
        else{
            std::cout << "Invalid input." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    std::ifstream in("numbers.txt");
    int number;

    while (in >> number) {
        if (number == b){
            std::cout << "Number found!" << std::endl;
            return 0;
        }
    }
    std::cout << "Number not found." << std::endl;
}
