#include <iostream>
#include <limits>
#include <list>
#include <ostream>
#include <iterator>
#include <algorithm>


int main(){
    std::list<char> chars {};
    std::cout << "Enter length of list of characters: " << std::endl;
    int len {};
    while (true){
        if (std::cin >> len && len > 0){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Enter elements of list: " << std::endl;
    for (int i {0}; i < len; i++){
        char value {};
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
        chars.push_back(value);
    }
    std::cout << "After replacing digits with '_' the list is: " << std::endl;
    std::replace_copy_if(chars.begin(), chars.end(), std::ostream_iterator<char>(std::cout, " "), 
        [](char c) { return std::isdigit(c); }, '_');
}