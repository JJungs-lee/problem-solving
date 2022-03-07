#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_N 101

bool graph[MAX_N][MAX_N] = {0,};
bool is_visited[MAX_N] = {0,};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	int start, end;
	cin >> n >> start >> end >> m;

	int child, parents;
	for (int i = 0; i < m; ++i) {
		cin >> child >> parents;
		graph[child][parents] = graph[parents][child] = true;
	}

	queue<pair<int, int>> q;
	q.push({start, 0});
	is_visited[start] = true;

	while (!q.empty()) {
		auto [cur, cnt] = q.front();
		q.pop();
		if (cur == end) {
			cout << cnt << endl;
			return 0;
		}

		for (int i = 1; i <= n; ++i) {
			if (!is_visited[i] && graph[cur][i]) {
				q.push({i, cnt + 1});
				is_visited[i] = true;
			}
		}
	}
	
	cout << "-1" << endl;

	return 0;
}