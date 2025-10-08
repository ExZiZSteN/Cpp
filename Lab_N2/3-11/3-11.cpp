#include <limits>
#include "solution.h"


int main(){
    std::list<int> lst1 {};
    std::list<int> lst2 {};
    int lstLenght {};
    std::cout << "Enter lenght of lists: " << std::endl;
    while (true){
        if (std::cin >> lstLenght && lstLenght > 0){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Enter elements of first list: " << std::endl;
    for (int i {0}; i < lstLenght; i++){
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
        lst1.push_back(value);
    }
    std::cout << "Enter elements of second list: " << std::endl;
    for (int i {0}; i < lstLenght; i++){
        int value {};
        std:: cout << "Enter " << i + 1 << " element of list2: ";
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
        lst2.push_back(value);
    }
    combineList(lst1, lst2);
    std:: cout << "After combining two lists current list is: "  << std::endl;
    for (const auto& item : lst2){
        std:: cout << item << " ";
    }
}