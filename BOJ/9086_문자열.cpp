#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		string str;
		cin >> str;
		cout << str[0] << str[str.size() - 1] << '\n';
	}

	return 0;
}