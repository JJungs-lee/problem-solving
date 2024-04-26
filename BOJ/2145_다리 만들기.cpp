#include <iostream>
#include <queue>

using namespace std;

#define DIR 4

int n;
int map[101][101];

int dx[DIR] = {0, 0, 1, -1};
int dy[DIR] = {1, -1, 0, 0};

void find_island() {
	bool visited[101][101];
	for (int i = 0; i < n; ++i) {
		fill(visited[i], visited[i] + n, false);
	}

	int mark = 2;
	queue<pair<int, int>> q;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] == 1 && !visited[y][x]) {
				map[y][x] = mark;
				q.push({y, x});
				visited[y][x] = true;

				while (!q.empty()) {
					auto [cur_y, cur_x] = q.front();
					q.pop();

					for (int i = 0; i < DIR; ++i) {
						int nx = cur_x + dx[i];
						int ny = cur_y + dy[i];

						if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
							continue;
						}
						if (map[ny][nx] == 1) {
							q.push({ny, nx});
							visited[ny][nx] = true;
							map[ny][nx] = mark;
						}
					}
				}
				mark++;
			}
		}
	}
}

int find_short_bridge() {
	int dist[101][101];
	for (int i = 0; i < n; ++i) {
		fill(dist[i], dist[i] + n, -1);
	}

	queue<pair<int, int>> q;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j]) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	int ans = 999999;
	while (!q.empty()) {
		auto [cur_y, cur_x] = q.front();
		q.pop();

		for (int i = 0; i < DIR; ++i) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;

			if (map[ny][nx] == map[cur_y][cur_x])
				continue;

			if (map[ny][nx] != 0) {
				ans = min(ans, dist[ny][nx] + dist[cur_y][cur_x]);
			} else {
				map[ny][nx] = map[cur_y][cur_x];
				dist[ny][nx] = dist[cur_y][cur_x] + 1;
				q.push({ny, nx});
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}
	find_island();
	cout << find_short_bridge();

	return 0;
}