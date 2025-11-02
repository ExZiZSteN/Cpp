#include "Fraction.h"
#include <limits>

int main(){
    std::cout << "Entter first fraction (numerator and denominator):" << std::endl;
    int num1, den1, num2, den2;
    while (true){
        if (std::cin >> num1 >> den1){
            if (den1 != 0){
                break;
            }
            else{
                std::cout << "Denominator can't be zero. Enter again" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else{
            std::cout << "Invalid input. Plesae enter integers." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Entter second fraction (numerator and denominator):" << std::endl;
    Fraction fraction1(num1,den1);
        while (true){
        if (std::cin >> num2 >> den2){
            if (den2 != 0){
                break;
            }
            else{
                std::cout << "Denominator can't be zero. Enter again" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else{
            std::cout << "Invalid input. Plesae enter integers." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    Fraction fraction2(num2,den2);
    int digit;
    std::cout << "Enter an integer digit:" << std::endl;
    while (true){
        if (std:: cin >> digit){
            break;
        }
        else{
            std::cout << "Invalid input. Plesae enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    Fraction result = fraction1 * fraction2 - digit;
    fraction1.print();
    std::cout << " * ";
    fraction2.print(); 
    std::cout << " - " << digit << " = ";
    result.print();
}