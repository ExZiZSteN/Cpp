#include <iostream>
#include <list>
#include <algorithm>
#include <limits>

int main(){
    std::list<int> L1 {};
    std::list<int> L2 {};
    int L1Lenght {};
    int L2Lenght {};
    std::cout << "Enter lenght of first list" << std::endl;
    while (true){
        if (std::cin >> L1Lenght && L1Lenght % 2 == 0){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Enter elements of first list: " << std::endl;
    for (int i {0}; i < L1Lenght; i++){
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
        L1.push_back(value);
    }
    std::cout << "Enter lenght of second list" << std::endl;
    while (true){
        if (std::cin >> L2Lenght && L2Lenght % 2 == 0){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cout << "Enter elements of second list: " << std::endl;
    for (int i {0}; i < L2Lenght; i++){
        int value {};
        std::cout << "Enter " << i + 1 << " element of list: ";
        while (true){
            if (std::cin >> value){
                break;
            }
            else{
                std::cout << "Invalid input. Enter valid value" <<  std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        L2.push_back(value);
    }
    std::list<int> :: iterator mid = L1.begin();
    std::advance(mid, L1Lenght / 2);
    std::swap_ranges(L1.begin(), mid,mid);
    std::list<int> :: iterator mid2 = L2.begin();
    std::advance(mid2,L2Lenght / 2);
    std::rotate(L2.begin(),mid2,L2.end());
    std::cout << "First list after swaping: " << std::endl;
    for (const auto& item : L1){
        std:: cout << item << " ";
    }
    std:: cout << std::endl;
    std::cout << "Second list after rotating: " << std::endl;
    for (const auto& item : L2){
        std::cout << item << " ";
    }
}