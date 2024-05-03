#include <iostream>
#include <string>

using namespace std;

int main() {
	int testCase;
	int n;
	string str;

	cin >> testCase;
	while (testCase--) {
		cin >> n >> str;
		for (int i = 0; i < str.size(); ++i) {
			if (n == i + 1)
				continue;
			else
				cout << str[i];
		}
		cout << endl;
	}
	return 0;
}