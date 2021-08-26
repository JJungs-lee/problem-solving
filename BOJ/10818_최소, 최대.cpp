#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

int main() {
	int n, num;
	int max_num = INT_MIN;
	int min_num = INT_MAX;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		max_num = max(max_num, num);
		min_num = min(min_num, num);
	}

	printf("%d %d", min_num, max_num);

	return 0;
}