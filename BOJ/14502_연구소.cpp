#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int DIR = 4;
const int MAX_SIZE = 8;

int n, m;
int map[MAX_SIZE][MAX_SIZE];
int dx[DIR] = {-1, 1, 0, 0};
int dy[DIR] = {0, 0, -1, 1};

int res = INT_MIN;
vector<pair<int, int>> v;

void bfs() {
	int copy_map[MAX_SIZE][MAX_SIZE];
	copy(&map[0][0], &map[0][0] + 64, &copy_map[0][0]);

	queue<pair<int, int>> q;
	for (pair<int, int> virus : v) {
		q.push(virus);
	}

	while (!q.empty()) {
		auto [cy, cx] = q.front();
		q.pop();

		for (int i = 0; i < DIR; ++i) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;

			if (!copy_map[ny][nx]) {
				copy_map[ny][nx] = 2;
				q.push({ny, nx});
			}
		}
	}

	int sum = 0;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (!copy_map[y][x])
				sum++;
		}
	}
	res = max(sum, res);
}

void backtracking(int count) {
	if (count == 3) {
		bfs();
		return;
	}

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			if (!map[y][x]) {
				map[y][x] = 1;
				backtracking(count + 1);
				map[y][x] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			cin >> map[y][x];
			if (map[y][x] == 2)
				v.push_back({y, x});
		}
	}

	backtracking(0);

	cout << res;

	return 0;
}