#include <iostream>
#include <queue>

using namespace std;

const int MAX_DIR = 6;

int dr[MAX_DIR] = {-2, -2, 0, 0, 2, 2};
int dc[MAX_DIR] = {-1, 1, -2, 2, -1, 1};

int n;
int r1, c1, r2, c2;
int map[201][201];

void solve() {
	if (r1 == r2 && c1 == c2) {
		cout << "0";
		return;
	}

	queue<pair<int, int>> q;
	q.push({r1, c1});
	map[r1][c1] = 0;

	while (!q.empty()) {
		auto [cur_r, cur_c] = q.front();
		q.pop();

		if (cur_r == r2 && cur_c == c2) {
			cout << map[cur_r][cur_c];
			return;
		}

		for (int i = 0; i < MAX_DIR; ++i) {
			int next_r = cur_r + dr[i];
			int next_c = cur_c + dc[i];

			if (next_r < 0 || next_c < 0 || next_r >= n || next_c >= n)
				continue;
			if (!map[next_r][next_c]) {
				map[next_r][next_c] = map[cur_r][cur_c] + 1;

				q.push({next_r, next_c});
			}
		}
	}
	cout << "-1";
};

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;

	solve();

	return 0;
}