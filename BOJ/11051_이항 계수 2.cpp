#include <iostream>

using namespace std;

// static �� �ڵ����� 0���� �ʱ�ȭ ���شٰ� ��.
static long long memo[1001][1001];

long long binomialCoefficient(int n, int r) {

	if(memo[n][r] > 0) {
		return memo[n][r];
	}
	if(r == 0 || n == r) {
		return memo[n][r] = 1;
	}

	return memo[n][r] = (binomialCoefficient(n - 1, r - 1) + binomialCoefficient(n - 1, r)) % 10007;
}

int main() {
	int n, k;

	cin >> n >> k;
	binomialCoefficient(n, k);
	
	cout << memo[n][k];
	return 0;
}