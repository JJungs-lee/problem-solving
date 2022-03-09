#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 101
#define MAX_DIR 6
#define RIPE 1
#define UNRIPE 0
#define EMPTY -1

struct Point {
	int x;
	int y;
	int z;
};

// x, y, z
int m, n, h;
// z, y, x
int map[MAX_SIZE][MAX_SIZE][MAX_SIZE];

// up, down, left, right, front, back
Point dp[MAX_DIR] = {
	{0, 0, 1},
	{0, 0, -1},
	{1, 0, 0},
	{-1, 0, 0},
	{0, 1, 0},
	{0, -1, 0},
};

void bfs(queue<Point>& q) {
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < MAX_DIR; ++i) {
			int next_x = cur.x + dp[i].x;
			int next_y = cur.y + dp[i].y;
			int next_z = cur.z + dp[i].z;

			if (next_x < 0 || next_y < 0 || next_z < 0 ||
				next_x >= m || next_y >= n || next_z >= h) {
				continue;
			}

			if (map[next_z][next_y][next_x] == UNRIPE) {
				q.push({next_x,next_y,next_z});
				map[next_z][next_y][next_x] = map[cur.z][cur.y][cur.x] + 1;
			}
		}
	}
}

int answer() {
	int ret = -1;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				if (!map[i][j][k]) {
					return -1;
				}
				ret = max(ret, map[i][j][k]);
			}
		}
	}
	return ret - 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> m >> n >> h;
	queue<Point> q;

	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < m; ++k) {
				cin >> map[i][j][k];
				if (map[i][j][k] == RIPE) {
					q.push({k,j,i});
				}
			}
		}
	}

	bfs(q);
	cout << answer() << endl;

	return 0;
}