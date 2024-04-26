#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int map[101][101];
bool isVisit[101][101];

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	for (int iter = 0; iter < k; ++iter) {
		int lx, ly, rx, ry;
		cin >> lx >> ly >> rx >> ry;

		for (int y = ly; y < ry; ++y)
			for (int x = lx; x < rx; ++x)
				map[y][x] = -1;
	}

	vector<int> v;
	for (int y = 0; y < m; ++y) {
		for (int x = 0; x < n; ++x) {
			if (map[y][x] == -1 || isVisit[y][x])
				continue;

			queue<pair<int, int>> q;
			q.push({x, y});
			isVisit[y][x] = true;

			int width = 1;
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();

				for (int k = 0; k < 4; ++k) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					if (map[ny][nx] == -1 || isVisit[ny][nx])
						continue;
					q.push({nx, ny});
					isVisit[ny][nx] = true;
					width++;
				}
			}
			v.push_back(width);
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto num : v)
		cout << num << " ";

	return 0;
}