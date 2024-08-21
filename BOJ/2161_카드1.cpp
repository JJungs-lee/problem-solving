#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;

	for (int i = 1; i <= n; ++i) {
		q.push(i);
	}

	while (!q.empty()) {
		int num = q.front();
		cout << num << ' ';
		q.pop();
		if (q.empty())
			break;
		num = q.front();
		q.pop();
		q.push(num);
	}

	return 0;
}