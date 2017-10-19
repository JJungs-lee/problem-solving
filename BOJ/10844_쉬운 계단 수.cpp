#include <iostream>
#include <cstring>
#include <memory.h>

using namespace	std;

int lenght;
const long long MOD = 1000000000;
long long dp[101][10];

long long find(int l, int startNum) {
	if(startNum > 9 || startNum < 0) return 0;
	if(l == lenght) return 1;
	
	if(dp[l][startNum] != -1) {
		return dp[l][startNum];
	}
	return dp[l][startNum] = (find(l + 1, startNum + 1) + find(l + 1, startNum - 1)) % MOD;
}

int main() {

	long long sum = 0;
	cin >> lenght;
	memset(dp, -1, sizeof(dp));

	for(int i = 1; i < 10; ++i) {
		sum += find(1, i);
	}
	cout << sum%MOD;
	return 0;
}

#if 0
// 내가 풀었던 소스 
// 초기화랑 ret을 사용을 안했어도 됬는데 이상하게 풀었던 것 같음.
#include <iostream>
#include <cstring>
#include <memory.h>

using namespace	std;


int lenght;
const long long MOD = 1000000000;
long long dp[1001][10];

long long find(int l, int startNum) {
	if(l == lenght) return 1;

	long long& ret = dp[l][startNum];

	if(ret != 0) {
		return ret;
	}
	if(startNum - 1 >= 0) {
		ret = (ret + find(l + 1, startNum - 1)) % MOD;
	}
	if(startNum + 1 < 10) {
		ret = (ret + find(l + 1, startNum + 1)) % MOD;
	}

	return ret;
}

int main() {

	long long sum = 0;
	cin >> lenght;
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i < 10; ++i) {
		sum += find(1, i);
	}
	cout << sum;
	return 0;
}
#endif