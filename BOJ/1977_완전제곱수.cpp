#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;
	int sum = 0;
	int res = 87654321;
	for (int i = 1; i <= 100; ++i) {
		int mul = i * i;
		if (m <= mul && mul <= n) {
			sum += mul;
			res = min(res, mul);
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << res;

	return 0;
}