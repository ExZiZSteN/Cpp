#include <iostream>
#include <limits>
using namespace std;

void square(int x){
    string result = "";
    for (int i{}; i  <= x; i++){
        for (int j{}; j <= x; j++){
            result += "*";
        }
        result += "\n";
    }
    cout << result;
}

int main(){
    int number {};
    cout << "Enter number of rows and columns of square:" << endl;
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
    cout << "Your square:" << endl;
    square(number);
}