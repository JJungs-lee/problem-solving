#include <algorithm>
#include <iostream>

using namespace std;
int n, m, k;
int r, c;
int notebook[42][42];
int sticker[12][12];

void rotation() {
	int tmp[12][12];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = sticker[i][j];

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			sticker[j][r - i - 1] = tmp[i][j];
		}
	}
	swap(r, c);
}

bool is_pasted(int x, int y) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (notebook[y + i][x + j] && sticker[i][j])
				return false;
		}
	}

	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (sticker[i][j])
				notebook[y + i][x + j] = 1;
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> sticker[i][j];
			}
		}
		bool flag = false;
		for (int rot = 0; rot < 4; ++rot) {
			for (int y = 0; y <= n - r; ++y) {
				for (int x = 0; x <= m - c; ++x) {
					if (is_pasted(x, y)) {
						flag = true;
						break;
					}
				}
				if (flag)
					break;
			}
			if (flag)
				break;
			rotation();
		}
	}

	int res = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (notebook[i][j])
				res++;
		}
	}
	cout << res;

	return 0;
}