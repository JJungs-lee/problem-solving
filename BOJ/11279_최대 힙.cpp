#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int num;
	priority_queue<int, vector<int>> pq;

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &num);
		if (num == 0) {
			if (pq.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top());
				pq.pop();
			}
			continue;
		}
		pq.push(num);
	}

	return 0;
}