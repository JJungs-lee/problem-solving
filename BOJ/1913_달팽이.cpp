#include <iostream>
using namespace std;

int map[1001][1001];

enum {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, find_num;
	cin >> n >> find_num;

	int cx = n / 2, cy = n / 2;
	int ret_x = 0, ret_y = 0;
	int dir = UP;      // 방향
	int mv_count = 0;  // 몇번 이동했는지
	int max_mv_count = 1;
	int change_dir_count = 0;

	for (int i = 1; i <= n * n; ++i) {
		map[cy][cx] = i;
		if (i == find_num) {
			ret_x = cx + 1;
			ret_y = cy + 1;
		}
		cy += dy[dir % 4];
		cx += dx[dir % 4];
		mv_count++;

		// 해당 방향으로 max까지 이동했는지
		if (mv_count == max_mv_count) {
			dir++;
			mv_count = 0;
			change_dir_count++;
		}

		if (change_dir_count == 2) {
			max_mv_count++;
			change_dir_count = 0;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << ret_y << ' ' << ret_x << '\n';

	return 0;
}