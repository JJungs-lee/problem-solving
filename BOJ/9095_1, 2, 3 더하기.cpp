#include <iostream>

using namespace std;
//1 2 3
// n을 1로 2로 3으로 뺴면서 DP
int dp[12];

int main() {

	dp[0] = 0;
	// 1
	dp[1] = 1;
	// 11 2 
	dp[2] = 2;
	// 111 12 21 3 
	dp[3] = 4;
	// 1111 112 121 211 31 13 4
	for(int i = 4; i <= 11; ++i) {
		dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
	}

	int testCase;
	cin >> testCase;
	while(testCase--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	return 0;
}