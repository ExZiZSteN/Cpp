#include <iostream>
#include <vector>
using namespace std;

int * add(vector<int> add,vector<int> ins, int pos){
    vector<int> arr3;
    for (int i {0}, len {add.size()}; i < len; i ++){
        if (i == pos){
            for (int j {0}, len2 {ins.size()}; j < len2; j++){
                arr3.push_back(ins[j]);
            }
        }
        arr3.push_back(add[i]);
    }
    int *result = {&arr3[0]};
    return result;
    
}


int main(){
    vector<int> arr1 {};
    vector<int> arr2 {};
    int n {};
    cout << "Enter len of arr1 ";
    cin >> n;
    for (int i {}; i < n; i++){
        int number;
        cout << "enter " << i+1 << " number ";
        cin >> number;
        arr1.push_back(number);
    };
    int n2 {};
    cout << "Enter len of arr2 ";
    cin >> n2;
    int j {0};
    for (j; j < n2; j++){
        int number;
        cout << "enter " << j+1 << " number ";
        cin >> number;
        arr2.push_back(number);
    };
    cout << "First array: ";
    for (int i {0}, len {arr1.size()}; i < len; i++){
        cout << arr1[i] << " ";
    }
    cout << endl << "Second array: ";
    for (int i {0}, len {arr2.size()}; i < len; i++){
        cout << arr2[i] << " ";
    }
    int pos {};
    cout << endl << "Enter position to insert second array into first: ";
    cin >> pos;
    int *result = add(arr1, arr2, pos);
    cout << "Resulting array: ";
    for (int i {0}, len {arr1.size() + arr2.size()}; i < len; i++){
        cout << *(result + i) << " ";
    }
}