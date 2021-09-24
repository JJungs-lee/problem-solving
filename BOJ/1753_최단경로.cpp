#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
Graph는 인접리스트를 뜻한다. G[i] 는 i번 정점에 연결된 간선의 정보(pair의 first)와 가중치(pair의 second)를 담고 있다.
start는 시작점을 의미한다.
결과는 vector로 반환되며, vector의 i번째 원소는 start부터 i번 정점 까지의 최단 거리를 뜻한다.
*/
const int inf = 987654321;

int vertexNum;  // 정점개수
int edgeNum;    // 간선개수
int startNum;   // 시작지점

vector<int> dijkstra(const vector<vector<pair<int, int> > >& graph, const int start) {
	vector<int> dist(vertexNum + 1, inf);  //반환할 값들의 집합
	dist[start] = 0;

	set<pair<int, int> > pq;

	pq.insert(make_pair(0, start));
	while (!pq.empty()) {
		auto top = *pq.begin();
		pq.erase(top);

		int current = top.second;
		const vector<pair<int, int> >& edges = graph[current];

		for (int i = 0; i < edges.size(); ++i) {
			int next = edges[i].first;
			//	그점이 가지고있는 가중치 > 현재 가지고있는 가중치+ 그점까지 가는 가중치
			if (dist[next] > dist[current] + edges[i].second) {
				pq.erase(make_pair(dist[next], next));
				pq.insert(make_pair(dist[current] + edges[i].second, next));
				dist[next] = dist[current] + edges[i].second;
			}
		}
	}
	return dist;
}

int main() {
	int startV;  // 출발정점
	int endV;    // 도착정점
	int weight;  // 가중치

	cin >> vertexNum >> edgeNum >> startNum;

	vector<vector<pair<int, int> > > graph(vertexNum + 1);

	for (int i = 0; i < edgeNum; ++i) {
		cin >> startV >> endV >> weight;
		graph[startV].push_back(make_pair(endV, weight));
	}
	vector<int> ret = dijkstra(graph, startNum);

	for (int i = 1; i <= vertexNum; ++i) {
		ret[i] == inf ? cout << "INF" << endl : cout << ret[i] << endl;
	}

	return 0;
}

#if 0
// 다른 풀이 방법
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX_V = 20001;

vector<pair<int, int> > adj[MAX_V];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int v, e;
	int start_v;
	cin >> v >> e >> start_v;

	vector<int> dist(v + 1, INF);
	priority_queue<pair <int, int>> pq;

	int start, end, value;
	for (int i = 0; i < e; ++i) {
		cin >> start >> end >> value;
		adj[start].push_back({end, value});
	}

	pq.push({0, start_v});
	dist[start_v] = 0;

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
	for (int i = 1; i < dist.size(); ++i) { 
		if (dist[i] == INF)
			cout << "INF" << endl;
		else
			cout << dist[i] << endl;
	}
	return 0;
}
#endif