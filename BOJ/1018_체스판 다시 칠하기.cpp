#include <iostream>
#include <string>
using namespace std;

string comp_str[2] = {
    "WBWBWBWB",
    "BWBWBWBW",
};
string map[52];

int map_compare(int y, int x, int mode) {
	int res = 0;

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (map[y + i][x + j] != comp_str[mode][j]) {
				res++;
			}
		}
		mode = (mode + 1) % 2;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	for (int i = 0; i < m; ++i)
		cin >> map[i];

	int res = 987654321;
	for (int i = 0; i <= m - 8; ++i) {
		for (int j = 0; j <= n - 8; ++j) {
			res = min(res, min(map_compare(i, j, 0), map_compare(i, j, 1)));
		}
	}
	cout << res;

	return 0;
}