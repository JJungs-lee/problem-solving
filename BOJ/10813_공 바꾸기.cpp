#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[101];

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		arr[i] = i;

	int i, j;
	while (m--) {
		cin >> i >> j;
		swap(arr[i], arr[j]);
	}

	for (int i = 1; i <= n; ++i)
		cout << arr[i] << ' ';

	return 0;
}