#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;
char map[101][101];
bool visited[101][101] = {false,};

pair<int, int> DIR[4] = {
	{0, -1},
	{0, 1},
	{1, 0},
	{-1,0},
};

void dfs(char color, int y, int x) {
	visited[y][x] = true;
	if (map[y][x] == 'R')
		map[y][x] = 'G';
	for (int i = 0; i < 4; ++i) {
		int next_y = DIR[i].first + y;
		int next_x = DIR[i].second + x;

		if (next_y >= 0 && next_x >= 0 && next_y < n && next_x < n) {
			if (!visited[next_y][next_x] && map[next_y][next_x] == color) {
				dfs(color, next_y, next_x);

			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				dfs(map[i][j], i, j);
				cnt++;
			}

		}
	}
	cout << cnt << " ";

	cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!visited[i][j]) {
				dfs(map[i][j], i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";

	return 0;
}
