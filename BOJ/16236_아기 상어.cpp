#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int N;
int map[21][21];
int dist[21][21];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int shark_size = 2;

tuple<int, int, int> eat_fish(int y, int x) {
	tuple<int, int, int> res = {0x989898, 0x989898, 0x989898};
	for (int i = 0; i < N; ++i)
		fill(dist[i], dist[i] + N, -1);

	queue<pair<int, int>> q;
	q.push({y, x});
	dist[y][x] = 0;
	map[y][x] = 0;

	while (!q.empty()) {
		auto [cy, cx] = q.front();
		q.pop();

		if (dist[cy][cx] >= get<0>(res))
			break;

		for (int k = 0; k < 4; ++k) {
			int ny = cy + dy[k];
			int nx = cx + dx[k];

			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (map[ny][nx] > shark_size || dist[ny][nx] >= 0)
				continue;

			dist[ny][nx] = dist[cy][cx] + 1;

			if (map[ny][nx] != 0 && map[ny][nx] < shark_size) {
				res = min(res, {dist[ny][nx], ny, nx});
			}
			q.push({ny, nx});
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int shark_x, shark_y;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_x = j;
				shark_y = i;
			}
		}
	}

	int count = 0;
	int res = 0;
	while (true) {
		auto [dist, y, x] = eat_fish(shark_y, shark_x);
		if (dist == 0x989898)
			break;

		count++;
		if (count == shark_size) {
			count = 0;
			shark_size++;
		}
		res += dist;

		shark_y = y;
		shark_x = x;
		map[shark_y][shark_x] = 9;
	}
	cout << res;

	return 0;
}