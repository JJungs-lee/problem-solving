#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n, num;
	priority_queue<int, vector<int>, greater<int> > pq;

	scanf("%d", &n);
	for (int i = 0; i < n * n; ++i) {
		scanf("%d", &num);
		if (pq.size() > n) {
			pq.pop();
		}
		pq.push(num);
	}
	int cnt = 1;
	do {
		pq.pop();
		cnt++;
	} while (cnt == n);

	printf("%d\n", pq.top());
	return 0;
}