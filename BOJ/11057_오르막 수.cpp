#include <cstring>
#include <iostream>

using namespace std;

int n;
long long dp[1001][11];
const int MOD = 10007;

long long solve(int pos, int num) {
	if (pos == n) return 1;

	long long ret = 0;

	if (dp[pos][num] != -1) {
		return dp[pos][num];
	}

	for (int i = num; i < 10; ++i) {
		ret += solve(pos + 1, i) % MOD;
	}
	return dp[pos][num] = ret;
}

int main() {
	int sum = 0;
	cin >> n;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < 10; ++i) {
		sum += solve(1, i);
	}
	cout << sum % MOD;
	return 0;
}