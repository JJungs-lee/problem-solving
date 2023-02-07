#include <iostream>
using namespace std;

int main() {
	int n;

	cin >> n;

	if (n < 100) {
		cout << n << endl;
	} else {
		int res = 99;

		for (int i = 100; i <= n; ++i) {
			int third = i / 100;
			int second = (i / 10) % 10;
			int first = i % 10;

			if (third - second == second - first)
				res++;
		}
		cout << res << endl;
	}
	return 0;
}