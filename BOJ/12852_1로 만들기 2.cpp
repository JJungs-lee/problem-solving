#include <algorithm>
#include <iostream>
using namespace std;

int dp[1000001];
int track[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	dp[1] = 0;
	track[1] = 0;

	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		track[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
			dp[i] = dp[i / 2] + 1;
			track[i] = i / 2;
		}
		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = dp[i / 3] + 1;
			track[i] = i / 3;
		}
	}

	cout << dp[n] << "\n";
	int idx = n;
	while (idx != 0) {
		cout << idx << ' ';
		idx = track[idx];
	}

	return 0;
}