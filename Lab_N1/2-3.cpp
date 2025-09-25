#include <iostream>
#include <limits>
using namespace std;


bool is35(int x){
    if (x % 15 == 0) return false;
    if (x % 3 == 0 || x % 5 == 0) return true;
}

int main(){
    int number {};
    cout << "Enter your number: " << endl;
    while (true) {
        if (cin >> number){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (is35(number)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}