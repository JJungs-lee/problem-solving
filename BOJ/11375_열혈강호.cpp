#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> node;
bool visited[1001];
int b[1001];

int dfs(int here) {
	if(visited[here]) return 0;

	visited[here] = 1;

	for(int i = 0; i < node[here].size(); ++i) {
		int there = node[here][i];

		if(!b[there] || dfs(b[there])) {
			b[there] = here;
			return 1;
		} 
	}
	return 0;
}
int main() {
	int N, M;
	cin >> N >> M;
	node.resize(N + 1);

	for(int i = 1; i <= N; ++i) {
		int num;
		int work;
		cin >> num;
		for(int j = 0; j < num; ++j) {
			cin >> work;
			node[i].push_back(work);
		}
	}
	int ret = 0;

	for(int i = 1; i <= N; ++i) {
		memset(visited, 0, sizeof(visited));
		if(dfs(i)) {
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}
