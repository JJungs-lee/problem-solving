#include <algorithm>
#include <deque>
#include <iostream>
using namespace std;

int n, m, r;
int board[301][301];

void solve() {
	int eidx = min(n, m) / 2;

	deque<int> dq;
	for (int i = 0; i < eidx; ++i) {
		dq.clear();

		for (int j = i; j < m - i; ++j)
			dq.push_back(board[i][j]);
		for (int j = i + 1; j < n - i; ++j)
			dq.push_back(board[j][m - 1 - i]);
		for (int j = m - 1 - i - 1; j >= i; --j)
			dq.push_back(board[n - 1 - i][j]);
		for (int j = n - 1 - i - 1; j >= i + 1; --j) {
			dq.push_back(board[j][i]);
		}

		rotate(dq.begin(), dq.begin() + (r % dq.size()), dq.end());

		int k = 0;
		for (int j = i; j < m - i; ++j)
			board[i][j] = dq[k++];
		for (int j = i + 1; j < n - i; ++j)
			board[j][m - 1 - i] = dq[k++];
		for (int j = m - 1 - i - 1; j >= i; --j)
			board[n - 1 - i][j] = dq[k++];
		for (int j = n - 1 - i - 1; j >= i + 1; --j)
			board[j][i] = dq[k++];
	}
}

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	cin >> n >> m >> r;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> board[i][j];
		}
	}

	solve();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}