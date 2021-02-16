#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

int m, n;
int box[1001][1001];
queue<Point> q;
// l, r, u, d
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

void bfs() {
	
	while(!q.empty()) {
		Point p = q.front();
		q.pop();

		for(int i = 0; i < 4; ++i) {
			int ny = p.first + dy[i];
			int nx = p.second + dx[i];

			if(ny >= 0 && ny < n && nx >= 0 && nx < m) {
				if(!box[ny][nx]) {
					box[ny][nx] = box[p.first][p.second] + 1;
					q.push(make_pair(ny, nx));
				}
			}
		}

	}
}

int main() {
	cin >> m >> n;

	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < m; ++x) {
			cin >> box[y][x];
			if(box[y][x] == 1) {
				q.push(make_pair(y, x));
			}
		}
	}

	bfs();

	int ret = 0;
	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < m; ++x) {
			if(box[y][x] == 0) {
				cout << "-1" << endl;
				return 0;
			} else {
				ret = max(ret, box[y][x]);
			}
		}
	}
	cout << ret - 1 << endl;
	return 0;
}