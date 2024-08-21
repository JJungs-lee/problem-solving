#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[1002][1002];
int dist[1002][1002];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({y, x});
	dist[y][x] = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (dist[ny][nx] != -1)
				continue;

			q.push({ny, nx});
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	int x, y;
	for (int i = 0; i < n; ++i) {
		fill(dist[i], dist[i] + m, -1);
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				dist[i][j] = 0;
			}
			if (map[i][j] == 2) {
				x = j;
				y = i;
			}
		}
	}

	bfs(x, y);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << dist[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}