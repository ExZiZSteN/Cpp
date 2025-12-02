#include <iostream>
#include <vector>
#include <fstream>
#include <limits>


void makeFile()
{
    int N = 10;
    std::ofstream out("numbers.txt");
    srand(time(0));
    for (int i = 0; i < N; i++) {
        int number = rand() % 10;
        for (int j = 0; j < number % 5;j++){
            int number2 = rand() % 10;
            out << number2 << " ";
        }
        out << "\n";
    }
    out.close();
}

int main()
{
    makeFile();
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