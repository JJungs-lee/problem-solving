#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	int card[101];
	bool used[101] = {false};

	scanf("%d %d ", &n, &m);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &card[i]);
	}

	used[n - 1] = used[n - 2] = used[n - 3] = true;

	int res = 0;
	do {
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				sum += card[i];
				cnt++;
			}
			if (cnt == 3)
				break;
		}
		if (sum <= m)
			res = max(res, sum);

		if (res == m)
			break;
	} while (next_permutation(used, used + n));
	printf("%d", res);

	return 0;
}