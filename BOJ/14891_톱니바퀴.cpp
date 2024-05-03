#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
string gear[4];

void solve(int idx, int dir) {
	int dirs[4] = {};
	dirs[idx] = dir;

	int left = idx;
	while (left > 0 && gear[left][6] != gear[left - 1][2]) {
		dirs[left - 1] = -dirs[left];
		left--;
	}

	int right = idx;
	while (right < 3 && gear[right][2] != gear[right + 1][6]) {
		dirs[right + 1] = -dirs[right];
		right++;
	}

	for (int i = 0; i < 4; ++i) {
		if (dirs[i] == -1) {
			rotate(gear[i].begin(), gear[i].begin() + 1, gear[i].end());
		} else if (dirs[i] == 1) {
			rotate(gear[i].begin(), gear[i].end() - 1, gear[i].end());
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 4; ++i)
		cin >> gear[i];

	int k;
	cin >> k;
	while (k--) {
		int idx, dir;
		cin >> idx >> dir;
		solve(idx - 1, dir);
	}

	int res = 0;
	for (int i = 0; i < 4; ++i) {
		if (gear[i][0] == '1') {
			res += (1 << i);
		}
	}
	cout << res;
	return 0;
}