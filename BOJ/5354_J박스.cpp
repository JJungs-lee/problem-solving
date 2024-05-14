#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int num;
		cin >> num;
		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				if (i == 0 || i == num - 1 || j == 0 || j == num - 1)
					cout << '#';
				else
					cout << 'J';
			}
			cout << '\n';
		}
		cout << '\n';
	}
	return 0;
}