#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;

	int arr[101][101] = { 0, };

	while (k--) {
		int px, py;
		cin >> px >> py;
		for (int i = py; i < py + 10; ++i) {
			for (int j = px; j < px + 10; ++j) {
				arr[i][j] = 1;
			}
		}
	}

	int res = 0;
	for (int i = 1; i < 101; ++i) {
		for (int j = 1; j < 101; ++j) {
			if (arr[i][j] == 1)
				res++;
		}
	}
	cout << res << '\n';

	return 0;
}