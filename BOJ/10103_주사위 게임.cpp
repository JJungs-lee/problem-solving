#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int a = 100, b = 100;
	int num1, num2;
	while (n--) {
		cin >> num1 >> num2;
		if (num1 < num2) {
			a -= num2;
		} else if (num1 > num2) {
			b -= num1;
		}
	}
	cout << a << '\n' << b;
	return 0;
}