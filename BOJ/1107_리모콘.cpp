#include <iostream>
#include <string>
using namespace std;

bool broken_button[11];

bool btn_set(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (broken_button[str[i] - '0'])
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	while (m--) {
		int num;
		cin >> num;
		broken_button[num] = true;
	}

	int ret = abs(n - 100);

	for (int i = 0; i <= 1000000; ++i) {
		string str = to_string(i);
		if (btn_set(str)) {
			int cnt = abs(n - i) + str.length();
			ret = min(ret, cnt);
		}
	}
	cout << ret;

	return 0;
}