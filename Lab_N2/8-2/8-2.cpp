#include <iostream>
#include "solution.h"
#include <limits>


int main(){
    std::list<std::string> lst {};
    int lstLenght {};
    std:: cout << "Input lenght of list of words: ";
    while (true){
        if (std::cin >> lstLenght && lstLenght > 0){
            break;
        }
        else{
            std:: cout << "Invalid input. Input valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    for (int i {}; i < lstLenght; i++){
        std::string value {};
        std::cout << "Enter " << i+1 << " value: ";
        while (true){
            if (std::cin >> value){
                break;
            }
            else{
                std::cout << "Invalid input. Input valid value"<< std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        lst.push_back(value);
    }
    std::deque<std::string> deq {solution((lst))};
    for (auto& i : deq){
        std::cout << i << " ";
    }
}