#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int maxAbs(vector<int> arr){
    int max = arr[0];
    for (int i{1}; i < arr.size(); i++){
        if (abs(arr[i]) > max) max = abs(arr[i]);
    }
    return max;

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
    cout << "The maximum absolute value in the array is: " << maxAbs(arr) << endl;
    
}