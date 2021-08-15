#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n, k;
	queue<int> q;

	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	int cnt = k - 1;

	printf("<");
	while (q.size() != 1) {
		if (!cnt) {
			cnt = k-1;
			printf("%d, ", q.front());
			q.pop();
		} else {
			q.push(q.front());
			q.pop();
			cnt--;
		}
	}
	printf("%d>", q.front());
	return 0;
}