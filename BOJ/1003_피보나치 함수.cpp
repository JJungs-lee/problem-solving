#include <iostream>
using namespace std;

int dp[42];
int n, tc;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 1;

	for (int i = 2; i < 41; ++i)
		dp[i] = dp[i - 1] + dp[i - 2];

	cin >> tc;
	while (tc--) {
		cin >> n;
		if (n == 0) {
			cout << "1 0" << endl;
		} else if (n == 1) {
			cout << "0 1" << endl;
		} else {
			cout << dp[n - 2] << " " << dp[n - 1] << '\n';
		}
	}

	return 0;
}