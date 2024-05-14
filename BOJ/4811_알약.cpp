#include <memory.h>

#include <iostream>
#include <string>

using namespace std;

long long dp[31][31];

long long findAnswer(int w, int h) {
	if (w < 0 || h < 0) {
		return 0;
	}

	if (w == 0 && h == 0) {
		return 1;
	}

	return findAnswer(w - 1, h + 1) + findAnswer(w, h - 1);
}

long long usingDp(int w, int h) {
	if (w < 0 || h < 0) {
		return 0;
	}

	if (w == 0 && h == 0) {
		return 1;
	}
	if (dp[w][h] != -1) {
		return dp[w][h];
	}

	return dp[w][h] = usingDp(w - 1, h + 1) + usingDp(w, h - 1);
}

int main() {
	int num;

	while (cin >> num) {
		if (num == 0) break;
		memset(dp, -1, sizeof(dp));
		cout << usingDp(num, 0) << endl;
	}

	return 0;
}