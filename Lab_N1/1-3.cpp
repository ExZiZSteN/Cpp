#include <iostream>
using namespace std;

int charToNum(char x){
    return (int)x - 48;
}

int main(){
    char x;
    cout << "Enter your character: " << endl;
    cin >> x;
    if ((int)x < 48 || (int)x > 57){
        cout << "Error: not a digit character" << endl;
        return 1;
    }
    int result = charToNum(x);
    cout << "Your character as a number is " << result << endl;
}