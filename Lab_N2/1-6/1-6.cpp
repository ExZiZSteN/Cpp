#include <iostream>
#include <limits>
#include "double_value.h"
using namespace std;

int main(){
    vector<int> v {};
    vector<int>::iterator vIt;
    deque<int> d {};
    
    deque<int>::iterator dIt;
    list<int> l {};
    list<int>::iterator lIt;
    int vLenght {};
    int dLenght {};
    int lLenght {};
    cout << "Enter length of vector: ";
    while (true) {
        if (cin >> vLenght && vLenght > 0 && vLenght % 2 != 0){
            break;
        }
        else{
            cout << "Invalid input. Enter valid value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    for (int i {0}; i < vLenght; i++){
        int value {};
        cout << "Enter " << i + 1 << " element of vector: ";
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
        v.push_back(value);
    }
    cout << "Enter length of deque: ";
    while (true) {
        if (cin >> dLenght && dLenght > 0 && dLenght % 2 != 0){
            break;
        }
        else{
            cout << "Invalid input. Enter valid value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    for (int i {0}; i < dLenght; i++){
        int value {};
        cout << "Enter " << i + 1 << " element of deque: ";
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
    cout << "Enter length of list: ";
    while (true) {
        if (cin >> lLenght && lLenght > 0 && lLenght % 2 != 0){
            break;
        }
        else{
            cout << "Invalid input. Enter valid value" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    for (int i {0}; i < lLenght; i++){
        int value {};
        cout << "Enter " << i + 1 << " element of list: ";
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
    Double(v);
    Double(d);
    Double(l);
    cout << "Vector after doubling: ";
    for (vIt = v.begin(); vIt != v.end(); vIt++){
        cout << *vIt << " ";
    }
    cout << endl << "Deque after doubling: ";
    for (dIt = d.begin(); dIt != d.end(); dIt++){
        cout << *dIt << " ";
    }
    cout << endl << "List after doubling: ";
    for (lIt = l.begin(); lIt != l.end(); lIt++){
        cout << *lIt << " ";
    }
}