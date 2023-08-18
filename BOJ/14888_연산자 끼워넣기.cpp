#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

enum oper { PLUS, MINUS, MUL, DIV };
int n;
int num[11];
int operators[4];
int ret_max = INT_MIN;
int ret_min = INT_MAX;

void slove(int ret, int idx) {
	if (idx == n) {
		ret_max = max(ret, ret_max);
		ret_min = min(ret, ret_min);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (operators[i]) {
			operators[i]--;

			switch (i) {
				case PLUS:
					slove(ret + num[idx], idx + 1);
					break;
				case MINUS:
					slove(ret - num[idx], idx + 1);
					break;
				case MUL:
					slove(ret * num[idx], idx + 1);
					break;
				case DIV:
					slove(ret / num[idx], idx + 1);
					break;
			}
			operators[i]++;
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> num[i];
	for (int i = 0; i < 4; ++i)
		cin >> operators[i];

	slove(num[0], 1);
	cout << ret_max << '\n' << ret_min << '\n';

	return 0;
}
