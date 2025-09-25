#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int * reverseBack(vector<int> arr){
    vector<int> reversed;
    for (int i{arr.size()-1}; i >= 0; i--){
        reversed.push_back(arr[i]);
    }
    int *result = {&reversed[0]};
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
    int * reversed = reverseBack(arr);
    cout << "Reversed array: ";
    for (int i{0}; i < n; i++){
        cout << *(reversed + i) << " ";
    }

}