#include <iostream>
using namespace std;

int map[2200][2200];
int k;
int count[3];

bool check(int x, int y, int n) {
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (map[y][x] != map[i][j])
				return false;
		}
	}
	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		count[map[y][x] + 1] += 1;
		return;
	}

	int n = z / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + j * n, y + i * n, n);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> map[i][j];
		}
	}

	solve(0, 0, k);
	for (int num : count)
		cout << num << '\n';

	return 0;
}