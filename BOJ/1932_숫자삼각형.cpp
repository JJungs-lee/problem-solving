#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n;
int cache[501][501];
int board[501][501];

int path(int y, int x) {
	if (y == n - 1) return board[y][x];

	int &ret = cache[y][x];

	if (ret != -1) return ret;

	return ret = max(path(y + 1, x), path(y + 1, x + 1)) + board[y][x];
}

int main() {
	memset(cache, -1, sizeof(board));

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= i; ++j) {
			cin >> board[i][j];
		}
	}

	cout << path(0, 0) << endl;

	return 0;
}