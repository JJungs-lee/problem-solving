#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	for (int i = 0; i < num; ++i) {
		for (int j = num - 1; j > i; --j) {
			cout << " ";
		}
		bool flag = true;
		for (int k = 0; k < i * 2 + 1; ++k) {
			if (flag)
				cout << "*";
			else
				cout << " ";
			flag ^= 1;
		}
		cout << "\n";
	}

	return 0;
}