#include <iostream>
using namespace std;

#define MAX_MAP 6144
#define MIN_STAR 5
char map[MAX_MAP][MAX_MAP];

void star(int y, int x, int size) {
	if (size == 3) {
		int div = MIN_STAR / 2;
		for (int i = 0; i <= div; ++i) {
			for (int j = 0; j < MIN_STAR; ++j) {
				if (i == 0 && j == div) map[y + i][x + j] = '*';
				if (i == 1 && ((j == div - 1) || (j == div + 1))) map[y + i][x + j] = '*';
				if (i == 2) map[y + i][x + j] = '*';
			}
		}
	} else {
		star(y, x + size / 2, size / 2);
		star(y + size / 2, x + size, size / 2);
		star(y + size / 2, x, size / 2);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (2 * n) - 1; ++j) {
			map[i][j] = ' ';
		}
	}

	star(0, 0, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2 * n - 1; ++j) {
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}