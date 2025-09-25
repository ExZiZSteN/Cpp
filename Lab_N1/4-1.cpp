#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int findFirst(vector<int>arr, int x){
    for (int i{}; i < 10; i++){
        if (arr[i] == x) return i;
    }
    return -1;
}



int main(){
    vector<int> arr{};
    int n {};
    
    cout << "Enter len of array: ";
    while (true) {
        if (cin >> n && n > 0){
            break;
        }
        else{
            cout << "Invalid input. Please enter a positive integer: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    for (int i {}; i < n; i++){
        cout << "enter " << i+1 << " number ";
        int number {};
        while (true) {
            if (cin >> number){
                break;
            }
            else{
                cout << "Invalid input. Please enter an integer: " << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
        arr.push_back(number);
    };
    int x {};
    cout << "Enter number to find: ";
    while (true) {
        if (cin >> x){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    int result = findFirst(arr, x);
    if (result != -1){
        cout << "First occurrence of " << x << " is at index " << result << endl;
    }
    else{
        cout << x << " not found in the array" << endl;
    }
}