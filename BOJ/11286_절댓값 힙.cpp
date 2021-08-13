#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

class cmp {
public:
	bool operator()(const int& a, const int& b) {
		if (abs(a) == abs(b)) {
			return a > b;
		} else {
			return abs(a) > abs(b);
		}
	}
};

int main() {
	int n, x;
	priority_queue<int, vector<int>, cmp> pq;
	scanf("%d", &n);

	while (n--) {
		scanf("%d", &x);
		if (x) {
			pq.push(x);
		} else {
			if (!pq.empty()) {
				printf("%d\n", pq.top());
				pq.pop();
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
