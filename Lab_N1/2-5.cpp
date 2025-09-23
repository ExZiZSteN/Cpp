#include <iostream>
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
    cout << "Input 3 numbers: " << endl;
    cin >> x;
    cin >> y;
    cin >> z;
    cout << "Maximum between your numbers is:" << endl;
    int result = max3(x,y,z);
    cout << result;
}