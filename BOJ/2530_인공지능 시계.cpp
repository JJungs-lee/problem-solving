#include <iostream>

using namespace std;

int main() {
	int h, m, s;
	int cookTime;
	int ret;

	cin >> h >> m >> s >> cookTime;
	ret = h * 3600 + m * 60 + s + cookTime;

	for (int i = 0; i < 10; ++i)
		if (ret >= 24 * 3600) ret -= 24 * 3600;

	cout << ret / 3600 << ' ';
	ret -= (ret / 3600) * 3600;
	cout << ret / 60 << ' ' << ret % 60;

	return 0;
}