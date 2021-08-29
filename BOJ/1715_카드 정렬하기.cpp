#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n, num;
	int res = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		pq.push(num);
	}
	while (pq.size() != 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();

		res += (a + b); 
		pq.push(a + b);
	}
	
	printf("%d", res);

	return 0;
}