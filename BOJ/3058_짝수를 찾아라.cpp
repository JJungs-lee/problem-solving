#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int sum = 0;
		int minN = 2147483647;

		for (int i = 0; i < 7; ++i) {
			int num;

			cin >> num;

			if (num % 2 == 0) {
				sum += num;
				minN = min(minN, num);
			}
		}
		cout << sum << ' ' << minN << endl;
	}
	return 0;
}