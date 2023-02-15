#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define RED 1
#define BLUE 2

bool bfs(int start_idx, vector<int> v[20001], int* color) {
	queue<int> q;
	q.push(start_idx);
	color[start_idx] = RED;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int next : v[cur]) {
			if (!color[next]) {
				q.push(next);
				color[next] = color[cur] == RED ? BLUE : RED;
			} else if (color[cur] == color[next]) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int V, E;
		cin >> V >> E;

		vector<int> v[20001];
		for (int i = 0; i < E; ++i) {
			int to, from;
			cin >> to >> from;
			v[to].push_back(from);
			v[from].push_back(to);
		}

		bool flag = false;
		int color[20001] = {
		    0,
		};
		for (int i = 1; i <= V; ++i) {
			if (!color[i])
				flag = bfs(i, v, color);
			if (!flag) {
				cout << "NO" << endl;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
	}

	return 0;
}
