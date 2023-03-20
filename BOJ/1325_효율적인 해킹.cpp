#include <string.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> graph[10001];
vector<int> hacking[10001];
bool visited[10001];

int hacked = 1;

void dfs(int start_idx) {
	visited[start_idx] = true;

	for (int next : graph[start_idx]) {
		if (!visited[next]) {
			hacked++;
			dfs(next);
		}
	}
}

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second < b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; ++i) {
		// A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
		// B에서 A로 갈 수 있다라고 생각하기
		int a, b;
		cin >> a >> b;

		graph[b].push_back(a);
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 1; i <= n; ++i) {
		memset(visited, false, sizeof(visited));
		dfs(i);
		pq.push(make_pair(i, hacked));
		hacked = 1;
	}

	int top_hacked = pq.top().second;

	while (!pq.empty() && top_hacked == pq.top().second) {
		cout << pq.top().first << ' ';
		pq.pop();
	}

	return 0;
}