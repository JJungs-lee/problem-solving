#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

int main() {
	int n, x;

	// max heap's top is middle value
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);

		if (!maxHeap.size()) {
			maxHeap.push(x);
		} else {
			if (x < maxHeap.top()) {
				maxHeap.push(x);
			} else {
				minHeap.push(x);
			}

			if (maxHeap.size() < minHeap.size()) {
				maxHeap.push(minHeap.top());
				minHeap.pop();
			} else if (maxHeap.size() > minHeap.size() + 1) {
				minHeap.push(maxHeap.top());
				maxHeap.pop();
			}
		}

		printf("%d\n", maxHeap.top());
	}
	return 0;
}
