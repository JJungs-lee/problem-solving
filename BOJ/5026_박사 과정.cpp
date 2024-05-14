#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int findPlus(string str);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		string str;

		cin >> str;

		if (str[1] == '=')
			cout << "skipped" << endl;
		else {
			int num = findPlus(str);
			cout << atoi(&str[0]) + atoi(&str[num]) << endl;
		}
	}

	return 0;
}

int findPlus(string str) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '+') {
			return i;
			break;
		}
	}
}
