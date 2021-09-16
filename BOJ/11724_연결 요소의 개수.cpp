#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[1002];  // Adjacency Matrix
bool visited[1002];

void dfs(int cur) {
	visited[cur] = true;

	for (auto i = adj[cur].begin(); i != adj[cur].end(); i++) {
		if (!visited[*i])
			dfs(*i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		if (visited[i])
			continue;

		dfs(i);
		ret++;
	}
	cout << ret;

	return 0;
}
