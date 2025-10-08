#include "solution.h"
#include <iostream>
#include <limits>


int main(){
    std::deque<int> d {};
    std::list<int> l {};
    int dLenght {};
    int lLenght {};
    std:: cout << "Enter lenght of list:" << std::endl;
    while (true){
        if(std::cin >> lLenght && lLenght >= 5){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std:: cout << "Enter elements of list: " << std::endl;
    for ( int i {0}; i < lLenght; i++){
        int value {};
        std::cout << "Enter " << i + 1 << " element of list: ";
        while (true){
            if (std::cin >> value){
                break;
            }
            else{
                std:: cout << "Invalid input. Enter valid value" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        l.push_back(value);
    }
    std::cout << "Enter length of deque: ";
    while (true) {
        if (std::cin >> dLenght && dLenght >= 5){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Enter elements of deque: " << std::endl;
    for ( int i {0}; i < dLenght; i++){
        int value {};
        std::cout << "Enter " << i + 1 << " element of deque: ";
        while (true){
            if (std::cin >> value){
                break;
            }
            else{
                std:: cout << "Invalid input. Enter valid value" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        d.push_back(value);
    }
    std::deque<int> lastFive = last_five_from_end(d);
    std:: cout << "After input five element from the end of deque '\n'after 5th element of list current list is: "  << std::endl;
    l.insert(fifth_from_end(l), lastFive.begin(), lastFive.end());
    for (const auto& item : l){
        std:: cout << item << " ";
    }
    
}