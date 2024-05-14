#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int num;
		int cnt = 0;
		char board[100][100];
		string str;

		cin >> str;
		// init
		num = (int)sqrt(str.size());

		for (int i = 0; i < num; ++i) {
			for (int j = 0; j < num; ++j) {
				board[i][j] = str[cnt];
				cnt++;
			}
		}

		for (int i = num - 1; i >= 0; --i) {
			for (int j = 0; j < num; ++j) {
				cout << board[j][i];
			}
		}
		cout << '\n';
	}

	return 0;
}