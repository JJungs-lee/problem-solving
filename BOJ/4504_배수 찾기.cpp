#include <iostream>

using namespace std;

int main() {
	int n;
	int num;

	cin >> n;

	while (cin >> num) {
		if (num == 0) break;

		num % n == 0 ? cout << num << " is a multiple of " << n << "." << endl : cout << num << " is NOT a multiple of " << n << "." << endl;
	}

	return 0;
}