#include <iostream>
#include <limits>
using namespace std;

int numLen(long x){
    int digits {0};
    do{
        digits++;
        x = x / 10;
    }
    while (x != 0);
        
    return digits;
}

int main(){
    int x;
    cout << "Enter value of number x: "<< endl;
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
    int result = numLen(x);
    cout << result << " Digits " << endl;
}