#include <iostream>

using namespace std;

static long long memo[100];

long long fibo(int n) {
	if (n <= 1) {
		return n;
	} else {
		return fibo(n - 1) + fibo(n - 2);
	}
}

long long fibo2(int n) {
	if (memo[n] > 0) {
		return memo[n];
	}

	if (n <= 1) {
		return memo[n] = n;
	} else {
		return memo[n] = fibo(n - 1) + fibo(n - 2);
	}
}

void fibo3(int n) {
	memo[1] = 1;
	memo[2] = 1;

	for (int i = 3; i <= n; ++i) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}
}

int main() {
	int n;
	cin >> n;
	fibo3(n);
	cout << memo[n];
	return 0;
}