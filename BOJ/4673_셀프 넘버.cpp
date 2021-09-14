#include <cstring>
#include <iostream>

using namespace std;

const int MAX_N = 10001;

int sol(int d) {
	int ret = d;
	while (d) {
		ret += (d % 10);
		d /= 10;
	}
	return ret;
}

int main() {
	bool self_num[MAX_N];

	fill(self_num, self_num + MAX_N, true);

	for (int i = 1; i < MAX_N; ++i) {
		int idx = sol(i);
		if (idx < MAX_N) {
			self_num[idx] = false;
		}
	}

	for (int i = 1; i < MAX_N; ++i) {
		if (self_num[i])
			printf("%d\n", i);
	}

	return 0;
}