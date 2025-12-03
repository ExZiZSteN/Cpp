#include <limits>
#include "Laba5.h"

int main()
{
    makeFile("numbers.txt");
    int k;
    std::cout << "Enter number multiplicity to find: ";
    while (true){
        if (std::cin >> k && k > 0){
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
    int sum = 0;
    while (in >> number) {
        if (number % k == 0){
            sum += number;
        }
    }
    in.close();
    std::cout << "Sum of numbers with multiplicity " << k << " is " << sum << std::endl;
}