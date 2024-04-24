#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, odd = 0, sum = 0, min_n = 100;

	for (int i = 0; i < 7; ++i) {
		cin >> x;

		if (x & 1) {
			odd += 1;
			sum += x;

			if (x < min_n) {
				min_n = x;
			}
		}
	}

	if (odd)
		cout << sum << "\n" << min_n;
	else
		cout << "-1";

	return 0;
}