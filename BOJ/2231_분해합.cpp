#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int size = static_cast<int>(log10(n) + 1);

	for (int i = n - 9 * size; i < n; ++i) {
		int sum = i;
		int tmp = i;
		while (tmp) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (sum == n) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;

	return 0;
}