#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n, m;
int map[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void melting() {
	vector<tuple<int, int, int>> v;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (!map[y][x])
				continue;

			int count = 0;
			for (int i = 0; i < 4; ++i) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n)
					continue;
				if (!map[ny][nx])
					count++;
			}
			v.push_back({y, x, count});
		}
	}
	for (auto cur : v) {
		int y, x, count;
		tie(y, x, count) = cur;
		map[y][x] = max(0, map[y][x] - count);
	}
}

int check_iceberg() {
	int count = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (map[y][x]) {
				count++;
			}
		}
	}

	if (count == 0)
		return 0;

	bool visited[301][301];

	for (int i = 0; i < n; ++i)
		fill(visited[i], visited[i] + m, 0);

	count = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (map[y][x] && !visited[y][x]) {
				count++;

				if (count >= 2)
					return 2;

				queue<pair<int, int>> q;
				visited[y][x] = true;
				q.push({y, x});

				while (!q.empty()) {
					auto [cur_y, cur_x] = q.front();
					q.pop();
					for (int i = 0; i < 4; ++i) {
						int nx = cur_x + dx[i];
						int ny = cur_y + dy[i];

						if (nx < 0 || ny < 0 || nx >= m || ny >= n)
							continue;
						if (!visited[ny][nx] && map[ny][nx]) {
							q.push({ny, nx});
							visited[ny][nx] = true;
						}
					}
				}
			}
		}
	}

	return 1;
}

int main() {
	cin >> n >> m;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> map[y][x];
		}
	}

	int year = 0;
	while (true) {
		year++;
		melting();
		int res = check_iceberg();
		if (res == 0) {
			cout << 0;
			return 0;
		} else if (res == 2) {
			cout << year;
			return 0;
		}
	}

	return 0;
}