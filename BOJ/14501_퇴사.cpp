#include <iostream>
#include <algorithm>
using namespace std;

int n;
int t[1002];
int p[1002];
int dp[1002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> t[i] >> p[i];
	}

	for (int i = n; i >= 1; --i) {
		if (i + t[i] - 1 <= n) {
			dp[i] = max(dp[i + 1], dp[i + t[i]] + p[i]);
		} else {
			dp[i] = dp[i + 1];
		}
	}
	cout << *max_element(dp + 1, dp + n + 1);

	return 0;
}