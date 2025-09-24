#include <iostream>
#include <limits>
using namespace std;


bool is2Digits(int x) {
	int div = (int)x / 10;
	if (div <= 9 && div != 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {

	int number {};
	cout << "Enter your number: " << endl;
	while (true){
		if (cin >> number){
			break;
		}
		else{
			cout << "Invalid input. Please enter an integer: " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << number << endl;
	if (is2Digits(number)) {
		cout << "true";
	}
	else {
		cout << "false";

	}
	return 0;
}

