#include <iostream>
using namespace std;

long long dp[101][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j != 0)
				dp[i][j] += dp[i - 1][j - 1];
			if (j != 9)
				dp[i][j] += dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}
	long long res = 0;
	for (int i = 0; i <= 9; ++i) {
		res += dp[n][i];
	}
	res %= 1000000000;
	cout << res;

	return 0;
}

#if 0
#include <memory.h>

#include <cstring>
#include <iostream>

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
#endif

#if 0
// ���� Ǯ���� �ҽ� 
// �ʱ�ȭ�� ret�� ����� ���߾ ��µ� �̻��ϰ� Ǯ���� �� ����.
#include <memory.h>

#include <cstring>
#include <iostream>

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