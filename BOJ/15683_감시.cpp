#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[9][9];
int res = 987654321;

vector<pair<int, int>> v;  // y, x

// 0은 빈 칸, 6은 벽, 1~5는 CCTV를 나타내고, 문제에서 설명한 CCTV의 종류이다.
#define EMPTY 0
#define WALL 6
#define WATCH 7

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool OOB(int y, int x) {  // Out Of Bounds 확인
	return y < 0 || y >= n || x < 0 || x >= m;
}

void fill_map(int y, int x, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(y, x) || map[y][x] == WALL)
			return;
		if (map[y][x] != 0)
			continue;
		map[y][x] = WATCH;
	}
}

void solve(int idx) {
	if (idx >= v.size()) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (map[i][j] == EMPTY)
					cnt++;
			}
		}
		res = min(res, cnt);
		return;
	}

	int tmp[9][9];
	auto [y, x] = v[idx];
	for (int dir = 0; dir < 4; ++dir) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				tmp[i][j] = map[i][j];
			}
		}

		if (map[y][x] == 1) {
			fill_map(y, x, dir);
		} else if (map[y][x] == 2) {
			fill_map(y, x, dir);
			fill_map(y, x, dir + 2);
		} else if (map[y][x] == 3) {
			fill_map(y, x, dir);
			fill_map(y, x, dir + 1);
		} else if (map[y][x] == 4) {
			fill_map(y, x, dir);
			fill_map(y, x, dir + 1);
			fill_map(y, x, dir + 2);
		} else {
			fill_map(y, x, dir);
			fill_map(y, x, dir + 1);
			fill_map(y, x, dir + 2);
			fill_map(y, x, dir + 3);
		}

		solve(idx + 1);

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				map[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
			if (map[i][j] > EMPTY && map[i][j] < WALL) {
				v.push_back({i, j});
			}
		}
	}
	solve(0);
	cout << res;

	return 0;
}