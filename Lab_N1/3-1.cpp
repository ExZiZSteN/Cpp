#include <iostream>
#include <limits>
using namespace std;

string listNums(int x){
    string result = "";
    for (int i {0}; i <= x; i++){
        result += to_string(i) + " ";
    }
    return result;
}


int main(){
    int number {};
    cout << "Enter your number:" << endl;
    while (true){
        if (cin >> number){
            break;        
        }
        else {
            cout << "Invalid input. Please enter an integer:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    string result = listNums(number);
    cout << "List of numbers from " << number << " to 0:" << endl;
    cout << result << endl;
}