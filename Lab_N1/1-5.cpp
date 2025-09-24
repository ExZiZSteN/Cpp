#include <iostream>
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
	cin >> number;
	
	
	if (is2Digits(number)) {
		cout << "true";
	}
	else {
		cout << "false";
	}
	return 0;
}

