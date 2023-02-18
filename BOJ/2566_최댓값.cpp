#include <iostream>

using namespace std;

int main() {
	int max_num = -1;
	int res_x, res_y;

	int num;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> num;
			if (max_num < num) {
				max_num = num;
				res_x = j;
				res_y = i;
			}
		}
	}
	cout << max_num << '\n'
	     << res_y + 1 << " " << res_x + 1 << '\n';

	return 0;
}