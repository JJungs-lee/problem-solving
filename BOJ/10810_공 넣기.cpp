#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int arr[101] = { 0, };
	int n, m;
	cin >> n >> m;

	int i, j, k;
	while (m--) {
		cin >> i >> j >> k;

		for (int idx = i; idx <= j; ++idx)
			arr[idx] = k;
	}
	for (int i = 1; i <= n; ++i)
		cout << arr[i] << ' ';

	return 0;
}