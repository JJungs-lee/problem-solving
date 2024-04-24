#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k, s, y;
	int arr[2][7] = {};

	cin >> n >> k;
	while (n--) {
		cin >> s >> y;
		arr[s][y]++;
	}

	int res = 0;
	for (int i = 1; i < 7; ++i) {
		for (int j = 0; j < 2; ++j) {
			res += arr[j][i] / k;
			if (arr[j][i] % k)
				res++;
		}
	}

	cout << res;

	return 0;
}