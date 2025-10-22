#include <iostream>
#include <list>
#include <algorithm>
#include <limits>

int main(){
    std::list<int> lst {};
    int LstLenght {};
    std::cout << "Enter legnth of list:";
    while (true){
        if (std::cin >> LstLenght && LstLenght > 0){
            break;
        }
        else{
            std::cout << "Invalid input. Input valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    for (int i {}; i < LstLenght; i++){
        int value {};
        std::cout << "Input " << i+1 << " number: ";
        while (true){
            if (std::cin>>value){
                break;
            }
            else{
                std::cout << "Invalid input. Input valid value." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

            }
        }
        lst.push_back(value);
    }
    auto negative = std::find_if(lst.begin(), lst.end(), [](int x){ return x < 0;});
    auto positive = std::find_if(lst.rbegin(), lst.rend(), [](int x){ return x > 0;});
    lst.insert(++negative, 0);
    lst.insert((++positive).base(), 0);
    std::cout << "After inserting 0 before first negativ element the list is: " << std::endl;
    for (const auto& item : lst){
        std:: cout << item << " ";
    }
}