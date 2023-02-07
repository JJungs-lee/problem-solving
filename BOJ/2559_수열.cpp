#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
	int n, k;
	int arr[100001];

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int sum = 0;
	int j = 0;
	int res = INT_MIN;
	for (int i = 0; i < n; ++i) {
		sum += arr[i];

		if (i >= k - 1) {
			res = max(res, sum);
			sum -= arr[j++];
		}
	}
	cout << res << endl;

	return 0;
}