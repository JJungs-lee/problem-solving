#include <iostream>

using namespace std;

#define NOT_CLEAN 0
#define WALL 1
#define CLEAN 2
#define MAX_DIR 4

enum { UP, RIGHT, DOWN, LEFT };
pair<int, int> dir[MAX_DIR] = {
	{-1, 0},
	{0, 1},
	{1, 0},
	{0, -1},
};

int map[51][51];

bool is_need_clean(int cur_y, int cur_x) {
	for (auto d : dir) {
		int next_x = cur_x + d.second;
		int next_y = cur_y + d.first;

		if (map[next_y][next_x] == NOT_CLEAN)
			return true;
	}
	return false;
}

void solve(int cur_y, int cur_x, int cur_dir) {
	int res = 0;

	while (true) {
		if (map[cur_y][cur_x] == NOT_CLEAN) {
			map[cur_y][cur_x] = CLEAN;
			res++;
		}

		if (!is_need_clean(cur_y, cur_x)) {
			int back_dir = (cur_dir + 2) % MAX_DIR;
			int next_y = cur_y + dir[back_dir].first;
			int next_x = cur_x + dir[back_dir].second;

			if (map[next_y][next_x] == WALL) {
				cout << res << '\n';
				break;
			} else {
				cur_y = next_y;
				cur_x = next_x;
			}
		} else {
			cur_dir = (cur_dir + 3) % MAX_DIR;
			int next_y = cur_y + dir[cur_dir].first;
			int next_x = cur_x + dir[cur_dir].second;

			if (map[next_y][next_x] == NOT_CLEAN) {
				cur_y = next_y;
				cur_x = next_x;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int cur_y, cur_x, cur_dir; 
	cin >> cur_y >> cur_x >> cur_dir;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) 
			cin >> map[y][x];
	}
	solve(cur_y, cur_x, cur_dir);

	return 0;
}