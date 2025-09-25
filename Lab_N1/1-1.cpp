#include <iostream>
#include <limits>
using namespace std;

double fraction (double x)
{
    int x1 = (int)x;
    return x - x1;
}

int main()
{
    cout << "Enter your number: " << endl;
    double number {};
    while (true){
        if (cin >> number){
            break;
        }
        else{
            cout << "Invalid input. Please enter a number: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    double result = fraction(number);
    cout << "Fractional part of your number is " << result << endl;
}