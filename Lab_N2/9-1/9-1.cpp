#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>


int main(){

    std::vector<int> V0 {};
    int V0Lenght {};
    std:: cout << "Input lenght of V0:";
    while (true)
    {
        if (std::cin >> V0Lenght && V0Lenght > 0){
            break;
        }
        else{
            std::cout << "Invalid input. Input valid value" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        }
    }
    for (int i {}; i < V0Lenght; i++){
        int value {};
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
        V0.push_back(value);
    }
    std::vector<std::vector<int>> vectors {};
    int N {};
    std::cout << "Input number of vectors in array:";
    while (true){
        if (std::cin >> N && N > 0){
            break;
        }
        else{
            std::cout << "Invalid input. Input valid value"<< std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
    for (int i {0}; i < N; i++){
        std::vector<int> V {};
        int VLength {};
        std::cout << "Input length of " << i +1 << " array: ";
        while (true){
            if (std::cin >> VLength && N > 0 && VLength > V0Lenght){
                break;
            }
            else{
                std::cout << "Invalid input. Input valid value"<< std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            }
        }
        for (int j {}; j < VLength; j++){
            int value {};
            std::cout << "Enter " << j+1 << " value: ";
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
            V.push_back(value);
        }
        vectors.push_back(V);
    }
    int counter {0};


    for (auto& i : vectors){
        if (std::includes(V0.begin(),V0.end(),i.begin(),i.end())){
            counter++;
        }
    }
    std::cout << counter;
}