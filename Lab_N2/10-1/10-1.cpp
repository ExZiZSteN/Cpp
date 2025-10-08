#include <iostream>
#include <vector>
#include <map>
#include <limits>
using namespace std;

int main() {
    vector<int> V;
    int n{};

    cout << "Enter number of elements: ";
    while (true) {
        if (cin >> n && n > 0) break;
        cout << "Invalid input. Please enter a positive integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    for (int i = 0; i < n; ++i) {
        int value{};
        cout << "Enter element " << i + 1 << ": ";
        while (!(cin >> value)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        V.push_back(value);
    }

    map<int, int> M;

    for (auto it = V.begin(); it != V.end(); ++it) {
        M[*it]++; 
    }

    cout << "Element : Count" << endl;
    for (auto it = M.begin(); it != M.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}
