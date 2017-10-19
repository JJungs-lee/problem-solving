#include <iostream>
#include <algorithm>
#include <cstring>
#include <memory.h>
using namespace std;

int n;
int arr[1001][3];
int dp[1001][3];

int usingDP(int pos, int flag) {
	if(pos == n) {
		return 0;
	}
	int &ret = dp[pos][flag];
	if(ret != -1) {
		return ret;
	}
	ret = 987654321;
	if(flag == 0) {
		ret = usingDP(pos + 1, 1) + arr[pos][1];
		ret = min(ret, usingDP(pos + 1, 2) + arr[pos][2]);
	}
	if(flag == 1) {
		ret = usingDP(pos + 1, 0) + arr[pos][0];
		ret = min(ret, usingDP(pos + 1, 2) + arr[pos][2]);
	}
	if(flag == 2) {
		ret = usingDP(pos + 1, 0) + arr[pos][0];
		ret = min(ret, usingDP(pos + 1, 1) + arr[pos][1]);
	}

	return ret;
}

int main() {

	cin >> n;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < 3; ++j) {
			cin >> arr[i][j];
		}
	}
	/* 다른 풀이법
	for(int i = 1; i < n; ++i) {
		
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + arr[i][0];
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + arr[i][1];
		arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + arr[i][2];
	}

	cout << min(min(arr[n - 1][0], arr[n - 1][1]), arr[n - 1][2]);
	*/

	memset(dp, -1, sizeof(dp));
 
	cout << min(min(usingDP(1, 0) + arr[0][0], usingDP(1, 1) + arr[0][1]), usingDP(1, 2) + arr[0][2]);
	return 0;
}
