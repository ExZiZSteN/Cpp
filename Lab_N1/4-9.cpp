#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int * findAll (vector<int> arr, int x){
    vector<int> positions;
    for (int i{0}; i < arr.size(); i++){
        if (arr[i] == x){
            positions.push_back(i);
        }
    }
    if (positions.empty()){
        positions.push_back(-1);
    }
    int *result = {&positions[0]};
    return result;
}

int main(){
    vector<int> arr;
    int n{};
    cout << "Enter number of elements: ";
    while (true){
        if (cin >> n && n > 0){
            break;
        }
        else{
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    for (int i{}; i < n; i++){
        cout << "Enter element " << i + 1 << ": ";
        int element{};
        while (true){
            if (cin >> element){
                arr.push_back(element);
                break;
            }
            else{
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    int x{};
    cout << "Enter the number to find: ";
    while (true){
        if (cin >> x){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    int * positions = findAll(arr, x);
    cout << "Positions of " << x << ": ";
    if (*(positions) == -1){
        cout << -1 << endl;
    }
    else{
        for (int i{0}; i < arr.size()-1; i++){
            if (*(positions + i) == -1) break;
            cout << *(positions + i) << " ";
        }
        cout << endl;
    }
}