#include <iostream>
#include <limits>
using namespace std;

int sum2(int x, int y){
    if (10 < x+y < 20) return 20;
    return x + y;
}

int main(){
    int x {};
    int y {};
    cout << "Enter two numbers: " << endl;
    while (true) {
        if (cin >> x){
            break;
        }
        else {
            cout << "Invalid input of x. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    while (true)
    {
        if (cin >> y){
            break;
        }
        else {
            cout << "Invalid input of y. Please enter integers: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    int result = sum2(x,y);
    cout << "Result is " << result << endl;
}