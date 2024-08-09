#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int len = str.size();
	for (int i = 0; i < len / 2; ++i) {
		if (str[i] != str[len - i - 1]) {
			cout << 0;
			return 0;
		}
	}
	cout << 1;
	return 0;
}