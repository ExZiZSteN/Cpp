#include <iostream>
#include <limits>
using namespace std;

int abs(int x){
    if (x < 0) return -x;
    return x;
}

int main(){
    int number {};
    cout << "Enter your number: " << endl;
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
    int result = abs(number);
    cout << "Absolute value of your number is " << result << endl;
}