#include <iostream>

using namespace std;

int gcd(int a, int b);
int lcd(int a, int b);

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int a, b;
		cin >> a >> b;
		cout << lcd(a, b) << ' ' << gcd(a, b) << endl;
	}
	return 0;
}

int gcd(int a, int b) {
	if (a < b)
		gcd(b, a);
	else if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcd(int a, int b) {
	return a * b / gcd(a, b);
}