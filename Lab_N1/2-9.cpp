#include <iostream>
#include <limits>
using namespace std;



int main(){
    int day {};
    cout << "Enter day of week (1-7): " << endl;
    while (true) {
        if (cin >> day && day >= 1 && day <= 7){
            break;
        }
        else{
            cout << "Invalid input. Please enter an integer between 1 and 7: " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    switch (day)
    {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    }
}