#include <array>
#include <climits>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	array<int, 100001> arr;

	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int l = 0, r = 0;
	int sum = arr[0];
	int res = INT_MAX;

	while (l <= r && r < n) {
		if (s <= sum) {
			res = min(res, r - l + 1);
			sum -= arr[l++];
		} else {
			sum += arr[++r];
		}
	}
	res == INT_MAX? cout << "0": cout << res;

	return 0;
}