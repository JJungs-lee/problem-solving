#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	int sum = 0;
	int min_num = 87654321;
	for (int i = m; i <= n; ++i) {
		if (i == 1)
			continue;
		bool flag = true;
		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			sum += i;
			min_num = min(min_num, i);
		}
	}

	if (sum)
		cout << sum << '\n'
		     << min_num;
	else
		cout << -1 << endl;
	return 0;
}