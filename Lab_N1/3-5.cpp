#include <iostream>
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
    cin >> x;
    int result = numLen(x);
    cout << result;
}