#include <iostream>
#include <limits>
using namespace std;

bool isEqual(int a, int b, int c){
    return (a == b && b == c);
}

int main(){
    int a;
    int b;
    int c;
    cout << "Enter three numbers: " << endl;
    while (true){
        if (cin >> a){
            break;
        }
        else{
            cout << "Invalid input. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true){
        if (cin >> b){
            break;
        }
        else{
            cout << "Invalid input. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true){
        if (cin >> c){
            break;
        }
        else{
            cout << "Invalid input. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    if (isEqual(a,b,c)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}