#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int arr[10];

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	do {
		reverse(arr + m, arr + n);
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
	} while (next_permutation(arr, arr + n));

	return 0;
}