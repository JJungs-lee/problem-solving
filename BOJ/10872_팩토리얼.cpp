#include <iostream>

using namespace std;

// Àç±Í ¹æ¹ý
int fact(int n) {
	if(n == 1) {
		return 1;
	}
	return n * fact(n - 1);
}

int main() {
	int n;
	
	cin >> n;
	 
	long long dp[13];
	dp[0] = 1;
	dp[1] = 1;
	for(int i = 1; i <= n; ++i) {
		dp[i] = dp[i - 1] * i;
	}

	cout << dp[n];
	return 0;
}