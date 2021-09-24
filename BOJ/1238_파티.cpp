#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
const int MAX_N = 1002;

vector<pair<int, int>> adj[MAX_N];

vector<int> dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	vector<int> dist(MAX_N + 1, INF);

	pq.push({0, start});
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;

		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextCost = cost + adj[here][i].second;

			if (dist[there] > nextCost) {
				dist[there] = nextCost;
				pq.push({-nextCost, there});
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;

	int u, v, w;
	for (int i = 0; i < m; ++i) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}
	vector<int> x_dist = dijkstra(x);

	int ret = -1;
	for (int i = 1; i <= n; ++i) {
		vector<int> i_dist = dijkstra(i);
		ret = max(ret, i_dist[x] + x_dist[i]);
	}
	cout << ret;

	return 0;
}