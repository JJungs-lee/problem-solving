#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

#define DIR 4

int n, rain;
int map[101][101];
bool visited[101][101];
int dx[DIR] = {-1, 1, 0, 0};
int dy[DIR] = {0, 0, -1, 1};

void init() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			visited[i][j] = false;
		}
	}
}

void dfs(int y, int x) {
	if (visited[y][x])
		return;

	visited[y][x] = true;

	for (int i = 0; i < DIR; i++) {
		int curY = y + dy[i];
		int curX = x + dx[i];
		if (0 <= curY && curY < n && 0 <= curX && curX < n) {
			if (!visited[curY][curX] && map[curY][curX] > rain)
				dfs(curY, curX);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int highest = INT_MIN;
	int lowest = INT_MAX;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> map[i][j];
			highest = max(map[i][j], highest);
			lowest = min(map[i][j], lowest);
		}
	}

	int ret = 1;
	for (rain = lowest; rain < highest; ++rain) {
		int cnt = 0;

		init();
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j] && map[i][j] > rain) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		ret = max(ret, cnt);
	}

	cout << ret;

	return 0;
}
