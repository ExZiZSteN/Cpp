#include <iostream>
#include <limits>
using namespace std;

bool isInRange(int a, int b, int num){
    if (a > b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
    return (num >= a && num <= b);
}

int main(){
    int a;
    int b;
    int num;
    cout << "Enter range a and b: " << endl;
    while (true) {
        if (cin >> a){
            break;
        }
        else{
            cout << "Invalid input of a. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true) {
        if (cin >> b){
            break;
        }
        else{
            cout << "Invalid input of b. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Enter your number: " << endl;

    while (true){
        if (cin >> num){
            break;
        }
        else{
            cout << "Invalid input of number. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (isInRange(a,b,num)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}