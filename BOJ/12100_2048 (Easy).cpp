#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n;
int res = 0;
int board[22][22];

enum DIR {
	LEFT,
	DOWN,
	RIGHT,
	UP,
	MAX_DIR
};

void update_board(int dir) {
	int arr[22] = {};
	bool check[22] = {
	    false,
	};

	// 왼쪽
	if (dir == LEFT) {
		for (int y = 0; y < n; ++y) {
			int idx = -1;
			for (int x = 0; x < n; ++x) {
				if (board[y][x]) {
					if (check[idx] != true && arr[idx] == board[y][x]) {
						arr[idx] *= 2;
						check[idx] = true;
					} else {
						arr[++idx] = board[y][x];
						check[idx] = false;
					}
				}
			}
			int count = 0;
			for (int i = 0; i < n; ++i) {
				if (count <= idx) {
					board[y][i] = arr[count++];
				} else {
					board[y][i] = 0;
				}
			}
		}
	} else if (dir == DOWN) {
		for (int x = 0; x < n; ++x) {
			int idx = -1;
			for (int y = n - 1; y >= 0; --y) {
				if (board[y][x]) {
					if (check[idx] != true && arr[idx] == board[y][x]) {
						arr[idx] *= 2;
						check[idx] = true;
					} else {
						arr[++idx] = board[y][x];
						check[idx] = false;
					}
				}
			}
			int count = 0;
			for (int i = n - 1; i >= 0; --i) {
				if (count <= idx) {
					board[i][x] = arr[count++];
				} else {
					board[i][x] = 0;
				}
			}
		}
	} else if (dir == RIGHT) {
		for (int y = 0; y < n; ++y) {
			int idx = -1;
			for (int x = n - 1; x >= 0; --x) {
				if (board[y][x]) {
					if (check[idx] != true && arr[idx] == board[y][x]) {
						arr[idx] *= 2;
						check[idx] = true;
					} else {
						arr[++idx] = board[y][x];
						check[idx] = false;
					}
				}
			}
			int count = 0;
			for (int i = n - 1; i >= 0; --i) {
				if (count <= idx) {
					board[y][i] = arr[count++];
				} else {
					board[y][i] = 0;
				}
			}
		}
	} else if (dir == UP) {
		for (int x = 0; x < n; ++x) {
			int idx = -1;
			for (int y = 0; y < n; ++y) {
				if (board[y][x]) {
					if (check[idx] != true && arr[idx] == board[y][x]) {
						arr[idx] *= 2;
						check[idx] = true;
					} else {
						arr[++idx] = board[y][x];
						check[idx] = false;
					}
				}
			}
			int count = 0;
			for (int i = 0; i < n; ++i) {
				if (count <= idx) {
					board[i][x] = arr[count++];
				} else {
					board[i][x] = 0;
				}
			}
		}
	}
}

void solve(int level) {
	if (level == 5) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				res = max(res, board[i][j]);
			}
		}
		return;
	}

	int tmp[22][22];
	for (int dir = LEFT; dir < MAX_DIR; ++dir) {
		// save
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				tmp[i][j] = board[i][j];
			}
		}

		update_board(dir);
		solve(level + 1);

		// rollback
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				board[i][j] = tmp[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
		}
	}

	solve(0);
	cout << res;

	return 0;
}