#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int n, m;
int res = 0;
int board[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({i, j});
			else if (board[i][j] == 2)
				chicken.push_back({i, j});
		}
	}

	int res = 987654321;
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.begin() + chicken.size() - m, 0);
	do {
		int dist = 0;
		for (auto h : house) {
			int temp = 987654321;
			for (int i = 0; i < chicken.size(); ++i) {
				if (!brute[i])
					continue;
				temp = min(temp, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
			}
			dist += temp;
		}
		res = min(res, dist);
	} while (next_permutation(brute.begin(), brute.end()));

	cout << res;
	return 0;
}