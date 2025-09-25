#include <iostream>
#include <limits>
using namespace std;


void rightTriangle(int x){
    string result = "";
    for (int i{}; i  < x; i++){
        for (int j{}; j < x-i-1; j++){
            result += " ";
        }
        for (int k{}; k <= i; k++){
            result += "*";
        }
        result += "\n";
    }
    cout << result;
}

int main(){
    int number {};
    cout << "Enter number of rows of right triangle:" << endl;
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
    cout << "Your right triangle:" << endl;
    rightTriangle(number);
}