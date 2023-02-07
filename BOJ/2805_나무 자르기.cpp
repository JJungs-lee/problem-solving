#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	long long low = 0;
	long long high = 0;

	vector<long long> trees(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> trees[i];
		high = max(high, trees[i]);
	}

	while (low < high) {
		long long mid = (low + high) / 2;

		long long sum = 0;
		for (long long tree : trees) {
			long long remain = tree - mid;
			if (remain > 0) {
				sum += remain;
			}
		}
		if (sum < m) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << low - 1 << endl;

	return 0;
}