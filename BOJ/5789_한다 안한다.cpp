#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tC;
	cin >> tC;

	while (tC--) {
		string str;
		cin >> str;

		str[str.size() / 2 - 1] == str[str.size() / 2] ? cout << "Do-it\n" : cout << "Do-it-Not\n";
	}
	return 0;
}