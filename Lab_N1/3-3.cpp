#include <iostream>
#include <limits>
using namespace std;

string chet(int x){
    string result = "";
    for (int i {0}; i <= x; i++){
        if (i % 2 == 0){
            result += to_string(i) + " ";
        }
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
    string result = chet(number);
    cout << "List of even numbers from 0 to " << number << ":" << endl;
    cout << result << endl;
}