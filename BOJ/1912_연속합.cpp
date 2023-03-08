#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[100001];
	int dp[100001];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	dp[0] = arr[0];
	int res = dp[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		res = max(dp[i], res);
	}
	cout << res << '\n';

	return 0;
}
