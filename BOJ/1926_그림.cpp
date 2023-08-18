#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[502][502];
bool visited[502][502];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int picture_count = 0;
	int max_size = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (map[i][j] == 0 || visited[i][j] == true)
				continue;
			picture_count++;

			int cur_size = 0;
			queue<pair<int, int>> q;
			q.push({i, j});
			visited[i][j] = true;

			while (!q.empty()) {
				cur_size++;
				auto [cur_y, cur_x] = q.front();
				q.pop();
				for (int idx = 0; idx < 4; ++idx) {
					int next_y = cur_y + dy[idx];
					int next_x = cur_x + dx[idx];
					if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
						continue;
					if (!visited[next_y][next_x] && map[next_y][next_x]) {
						q.push({next_y, next_x});
						visited[next_y][next_x] = true;
					}
				}
			}
			max_size = max(max_size, cur_size);
		}
	}
	cout << picture_count << '\n' << max_size;

	return 0;
}
