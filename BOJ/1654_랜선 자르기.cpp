#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int k, n;
	cin >> k >> n;

	long long low = 1;
	long long high = 0;

	vector<long long> v(k, 0);
	for (int i = 0; i < k; ++i) {
		cin >> v[i];
		high = max(high, v[i]);
	}

	long long res = 0;
	while (low <= high) {
		long long mid = (low + high) / 2;

		int sum = 0;
		for (int num : v) {
			sum += num / mid;
		}

		if (sum >= n) {
			res = max(res, mid);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	cout << res << endl;

	return 0;
}