#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int n, m, k;
string map[1001];
int dist[1001][1001][11];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}

	queue<tuple<int, int, int>> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 1;

	while (!q.empty()) {
		auto [cy, cx, cw] = q.front();
		q.pop();

		if (cy == n - 1 && cx == m - 1) {
			cout << dist[cy][cx][cw];
			return 0;
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx < 0 || ny < 0 || nx >= m || ny >= n)
				continue;

			int nw = cw;
			if (map[ny][nx] == '1')
				nw++;

			if (nw > k || dist[ny][nx][nw] > 0)
				continue;

			dist[ny][nx][nw] = dist[cy][cx][cw] + 1;
			q.push({ny, nx, nw});
		}
	}
	cout << -1;

	return 0;
}