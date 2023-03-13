#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	for (int i = 0; i < str.size() - 1; ++i) {
		for (int j = i; j < str.size(); ++j) {
			if (str[i] <= str[j]) swap(str[i], str[j]);
		}
	}
	cout << str;
	return 0;
}