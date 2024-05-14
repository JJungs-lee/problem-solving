#include <iostream>
using namespace std;

long long dp[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;

	for (int i = 4; i <= n; ++i) {
		dp[i] = (dp[i - 1] + dp[i - 2]);
	}

	cout << dp[n];

	return 0;
}