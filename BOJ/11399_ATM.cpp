#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int arr[1001];

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	sort(arr, arr + n);

	int sum = 0;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];
		res += sum;
	}

	cout << res;

	return 0;
}