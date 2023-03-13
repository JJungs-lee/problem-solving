#include <iostream>

using namespace std;

int findGCD(int sun, int mother);

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int a, b;
		int gcd;

		cin >> a >> b;
		gcd = findGCD(a, b);

		cout << a * b / gcd << endl;
	}
	return 0;
}

int findGCD(int a, int b) {
	if (a < b) return findGCD(b, a);
	if (b == 0) return a;
	return findGCD(b, a % b);
}
