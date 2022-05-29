#include <iostream>
#include <queue>

using namespace std;
#define MAX_AREA 1001
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};
int n, m;

char map[MAX_AREA][MAX_AREA];
int visited[MAX_AREA][MAX_AREA][2];

int bfs() {
	queue<pair<pair<int, int>, int>> q;

	visited[0][0][1] = 1;
	q.push({{0, 0}, 1});

	while (!q.empty()) {
		auto [cur, block] = q.front();
		q.pop();

		int cur_y = cur.first;
		int cur_x = cur.second;

		if (cur_y == n - 1 && cur_x == m - 1)
			return visited[cur_y][cur_x][block];

		for (int i = 0; i < 4; ++i) {
			int ny = cur_y + dy[i];
			int nx = cur_x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (map[ny][nx] == '1' && block) {
				visited[ny][nx][block - 1] = visited[cur_y][cur_x][block] + 1;
				q.push({{ny, nx}, block - 1});
			}
			if (map[ny][nx] == '0' && !visited[ny][nx][block]) {
				visited[ny][nx][block] = visited[cur_y][cur_x][block] + 1;
				q.push({{ny, nx}, block});
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> map[i];

	cout << bfs() << endl;

	return 0;
}
