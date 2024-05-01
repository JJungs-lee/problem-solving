#include <iostream>
#include <string>
using namespace std;

string map[128];

bool check(int x, int y, int n) {
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (map[y][x] != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		cout << map[y][x];
		return;
	}

	int n = z / 2;
	cout << "(";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			solve(x + j * n, y + i * n, n);
	cout << ")";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;

	for (int i = 0; i < k; ++i) {
		cin >> map[i];
	}

	solve(0, 0, k);

	return 0;
}