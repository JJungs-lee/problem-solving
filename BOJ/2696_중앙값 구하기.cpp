#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int tc, m, num;

	scanf("%d", &tc);
	while (tc--) {
		priority_queue<int, vector<int>, less<int>> max_heap;
		priority_queue<int, vector<int>, greater<int>> min_heap;

		scanf("%d", &m);
		printf("%d\n", m / 2 + 1);
		for (int i = 0; i < m; ++i) {
			scanf("%d", &num);
			if (!max_heap.size()) {
				max_heap.push(num);
			} else {
				if (num < max_heap.top()) {
					max_heap.push(num);
				} else {
					min_heap.push(num);
				}

				if (max_heap.size() < min_heap.size()) {
					max_heap.push(min_heap.top());
					min_heap.pop();
				}else if (max_heap.size() > min_heap.size() + 1) {
					min_heap.push(max_heap.top());
					max_heap.pop();
				}
			}
			if (!(i & 1)) {
				printf("%d ", max_heap.top());
			}
		}
		printf("\n");
	}

	return 0;
}