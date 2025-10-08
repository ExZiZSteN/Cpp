#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


int main()
{
    std::vector<int> vec {};
    int vectorLenght {};
    std::cout << "Enter lenght of vector:" << std::endl;
    while (true){
        if (std::cin >> vectorLenght && vectorLenght >= 3){
            break;
        }
        else{
            std::cout << "Invalid input. Enter valid number" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    for (int i {}; i < vectorLenght; i++){
        int value {};
        std:: cout << "Input " << i+1 << " value: ";
        while (true){
            if (std::cin >> value){
                break;
            }
            else{
                std:: cout << "Invalid input. Enter valid number" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>:: max(), '\n');
            }
        }
        vec.push_back(value);
    }
    std::sort(vec.begin(),vec.end());
    std::vector<int> res {};
    std::cout << "First three elements after sorting:"<<std::endl;
    std::copy(vec.begin(),vec.begin()+3,std::back_insert_iterator(res));
    for (int& i : res){
        std:: cout << i << " ";
    }
}