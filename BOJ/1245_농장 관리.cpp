#include <iostream>

using namespace std;

#define MAX_DIR 8

int n, m;

bool is_peak;
static int map[101][71];
static bool visited[101][71];

pair<int, int> dir[MAX_DIR] = {
	{-1, 0}, {-1, 1}, {0, 1}, {1, 1},
	{1, 0}, {1, -1}, {0, -1}, {-1, -1},
};

void dfs(int cur_y, int cur_x) {
	for (auto delta : dir) {
		int ny = cur_y + delta.first;
		int nx = cur_x + delta.second;

		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (map[ny][nx] > map[cur_y][cur_x])
				is_peak = false;

			if (!visited[ny][nx] && map[ny][nx] == map[cur_y][cur_x]) {
				visited[ny][nx] = true;
				dfs(ny, nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) 
			cin >> map[y][x];
	}

	int res = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) 
			if (!visited[y][x]) {
				is_peak = true;
				dfs(y, x);
				if (is_peak)
					res++;
			}
	}

	cout << res << '\n';

	return 0;
}