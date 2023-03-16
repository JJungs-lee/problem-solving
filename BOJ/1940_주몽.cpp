#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[15001];

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int i = 0;
	int j = n - 1;

	int res = 0;
	while (i < j) {
		if (arr[i] + arr[j] < m) {
			i++;
		} else if (arr[i] + arr[j] > m) {
			j--;
		} else {
			res++;
			i++;
			j--;
		}
	}
	cout << res;

	return 0;
}