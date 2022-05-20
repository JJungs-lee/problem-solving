#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int r, c;
char map[21][21];
bool visited[128] = {
    false,
};
int res = 0;
pair<int, int> DIR[4] = {
    {0, -1},
    {0, 1},
    {1, 0},
    {-1, 0},
};

void dfs(int y, int x, int cnt) {
	res = max(res, cnt);

	for (int i = 0; i < 4; ++i) {
		int next_y = y + DIR[i].first;
		int next_x = x + DIR[i].second;

		if (next_y >= r || next_x >= c || next_y < 0 || next_x < 0)
			continue;

		if (visited[map[next_y][next_x]] == true)
			continue;

		visited[map[next_y][next_x]] = true;
		dfs(next_y, next_x, cnt + 1);
		visited[map[next_y][next_x]] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			cin >> map[i][j];
		}
	}

	visited[map[0][0]] = true;
	dfs(0, 0, 1);

	cout << res;

	return 0;
}