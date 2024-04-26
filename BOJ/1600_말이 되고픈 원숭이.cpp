#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int k, w, h;
int map[201][201];
int dist[31][201][201];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int jump_dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int jump_dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

#define OOB(ny, nx) (ny < 0 || nx < 0 || ny >= h || nx >= w)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> map[i][j];
		}
	}

	queue<tuple<int, int, int>> q;
	q.push({0, 0, 0});
	dist[0][0][0] = 1;

	while (!q.empty()) {
		auto [cur_y, cur_x, count] = q.front();
		q.pop();

		if (count < k) {
			for (int i = 0; i < 8; ++i) {
				int nx = cur_x + jump_dx[i];
				int ny = cur_y + jump_dy[i];

				if (OOB(ny, nx) || dist[count + 1][ny][nx] || map[ny][nx] == 1)
					continue;
				dist[count + 1][ny][nx] = dist[count][cur_y][cur_x] + 1;
				q.push({ny, nx, count + 1});
			}
		}

		for (int i = 0; i < 4; ++i) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (OOB(ny, nx) || dist[count][ny][nx] || map[ny][nx] == 1)
				continue;
			dist[count][ny][nx] = dist[count][cur_y][cur_x] + 1;
			q.push({ny, nx, count});
		}
	}

	int ans = 0x7f7f7f7f;
	for (int i = 0; i < k + 1; i++) {
		if (dist[i][h - 1][w - 1])
			ans = min(ans, dist[i][h - 1][w - 1]);
	}
	if (ans != 0x7f7f7f7f)
		cout << ans - 1;
	else
		cout << -1;

	return 0;
}