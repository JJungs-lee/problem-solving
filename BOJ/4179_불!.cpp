#include <iostream>
#include <queue>
#include <string>

using namespace std;

string map[1001];
int fire_map[1001][1001];
int human_map[1001][1001];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int R, C;
	queue<pair<int, int>> fireQ;
	queue<pair<int, int>> q;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		fill(fire_map[i], fire_map[i] + C, -1);
		fill(human_map[i], human_map[i] + C, -1);
	}

	for (int y = 0; y < R; ++y) {
		cin >> map[y];
		for (int x = 0; x < C; ++x) {
			if (map[y][x] == 'J') {
				q.push({y, x});
				human_map[y][x] = 0;
			} else if (map[y][x] == 'F') {
				fireQ.push({y, x});
				fire_map[y][x] = 0;
			}
		}
	}

	while (!fireQ.empty()) {
		auto cur = fireQ.front();
		fireQ.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (fire_map[ny][nx] != -1 || map[ny][nx] == '#')
				continue;
			fireQ.push({ny, nx});
			fire_map[ny][nx] = fire_map[cur.first][cur.second] + 1;
		}
	}

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
				cout << human_map[cur.first][cur.second] + 1;
				return 0;
			}

			if (human_map[ny][nx] != -1 || map[ny][nx] == '#')
				continue;
			if (fire_map[ny][nx] != -1 && fire_map[ny][nx] <= human_map[cur.first][cur.second] + 1)
				continue;
			q.push({ny, nx});
			human_map[ny][nx] = human_map[cur.first][cur.second] + 1;
		}
	}
	cout << "IMPOSSIBLE";

	return 0;
}