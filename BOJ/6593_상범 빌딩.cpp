#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

#define MX 31

int main() {
	while (true) {
		int L, R, C;

		cin >> L >> R >> C;  // z, y, x;

		if (L == 0 && R == 0 && C == 0)
			break;

		char map[MX][MX][MX];
		int dist[MX][MX][MX];

		queue<tuple<int, int, int>> q;
		for (int z = 0; z < L; ++z) {
			for (int y = 0; y < R; ++y) {
				fill(dist[z][y], dist[z][y] + C, 0);
				for (int x = 0; x < C; ++x) {
					cin >> map[z][y][x];
					if (map[z][y][x] == 'S') {
						dist[z][y][x] = 0;
						q.push({z, y, x});
					}
				}
			}
		}
		bool is_escape = false;
		while (!q.empty()) {
			auto [cur_z, cur_y, cur_x] = q.front();
			q.pop();

			for (int k = 0; k < 6; ++k) {
				int nx = cur_x + dx[k];
				int ny = cur_y + dy[k];
				int nz = cur_z + dz[k];

				if (nx < 0 || ny < 0 || nz < 0 || nx >= C || ny >= R || nz >= L)
					continue;
				if (map[nz][ny][nx] == '#' || dist[nz][ny][nx] > 0)
					continue;

				dist[nz][ny][nx] = dist[cur_z][cur_y][cur_x] + 1;
				if (map[nz][ny][nx] == 'E') {
					cout << "Escaped in " << dist[nz][ny][nx] << " minute(s).\n";
					is_escape = true;
					break;
				}
				q.push({nz, ny, nx});
			}
		}

		if (!is_escape)
			cout << "Trapped!\n";
	}

	return 0;
}