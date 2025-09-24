#include <iostream>
#include <limits>
using namespace std;

int max3(int x,int y, int z){
    
    if (y > x) x = y;
    if (z > x) x = z;
    return x;
}

int main() {
    int x;
    int y;
    int z;
    cout << "Input number 1" << endl;
    while (true){
        if (cin >> x){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input number 2" << endl;
    while (true){
        if (cin >> y){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Input number 3" << endl;
    while (true){
        if (cin >> z){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cin >> y;
    cin >> z;
    cout << "Maximum between your numbers is:" << endl;
    int result = max3(x,y,z);
    cout << result;
}