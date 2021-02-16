#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int board[301][301];
queue <pair<int, int>> q;

int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };

void bfs(int b_size, int goal_y, int goal_x) {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		if (cur.first == goal_y && cur.second == goal_x) {
			cout << board[goal_y][goal_x] - 1 << endl;
			return;
		}

		for (int i = 0; i < 8; ++i) {
			int ny = cur.first + dy[i];
			int nx = cur.second + dx[i];
			
			if (ny < 0 || ny >= b_size || nx < 0 || nx >= b_size) {
				continue;
			}
			if(!board[ny][nx]) {
				q.push(make_pair(ny, nx));
				board[ny][nx] = board[cur.first][cur.second] + 1;
			}
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int board_size;
		pair<int, int> cur, goal;

		cin >> board_size;
		cin >> cur.first >> cur.second >> goal.first >> goal.second;

		memset(board, 0, sizeof(board));
		q = queue <pair<int, int>>();

		board[cur.first][cur.second] = 1;
		q.push(cur);
		bfs(board_size, goal.first, goal.second);
	}
	return 0;
}