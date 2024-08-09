#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;

	int res = 10;
	for (int i = 1; i < str.size(); ++i) {
		if (str[i - 1] != str[i])
			res += 10;
		else
			res += 5;
	}
	cout << res;

	return 0;
}