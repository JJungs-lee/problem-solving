#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> q;

	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();

	return 0;
}