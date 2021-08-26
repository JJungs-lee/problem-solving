#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
	int n;
	int max_num = INT_MIN;
	int idx = 0;

	for (int i = 0; i < 9; ++i) {
		scanf("%d", &n);
		if (max_num < n) {
			max_num = n;
			idx = i + 1;
		}
	}

	printf("%d\n%d", max_num, idx);

	return 0;
}