#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	int count = 0;
	for (int i = 1; i <= n; ++i) {
		if (n % i == 0) {
			count++;
			if (k == count) {
				cout << i << '\n';
				return 0;
			}
		}
	}

	cout << 0 << endl;
	return 0;
}