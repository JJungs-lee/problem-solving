#include <iostream>

using namespace std;

int n, m, k;
int cy, cx;
int map[22][22];

//    [2]
// [4][1][3]
//    [5]
//    [6]

int dice[7] = {
    0,
};

int move_dice[5][4] = {
    {},
    {4, 6, 3, 1},  // 동 | 4 <- 6, 6 <- 3, 3 <- 1, 1 <- 4
    {3, 6, 4, 1},  // 서
    {5, 6, 2, 1},  // 북
    {2, 6, 5, 1},  // 남
};

pair<int, int> move_pointer[5] = {
    {},
    {0, 1},   // 동
    {0, -1},  // 서
    {-1, 0},  // 북
    {1, 0},   // 남
};

void solve(int input) {
	int nx = cx + move_pointer[input].second;
	int ny = cy + move_pointer[input].first;

	// OOB check
	if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
		return;
	}
	// copy
	int temp[7];
	for (int i = 1; i < 7; ++i)
		temp[i] = dice[i];

	// move dice
	for (int i = 0; i < 4; ++i) {
		auto mv = move_dice[input];
		temp[mv[i]] = dice[mv[(i + 1) % 4]];
	}

	for (int i = 1; i < 7; ++i)
		dice[i] = temp[i];

	if (map[ny][nx] == 0) {
		map[ny][nx] = dice[6];
	} else {
		dice[6] = map[ny][nx];
		map[ny][nx] = 0;
	}
	cx = nx;
	cy = ny;
	cout << dice[1] << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> cy >> cx >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int input;
	while (k--) {
		cin >> input;
		solve(input);
	}

	return 0;
}