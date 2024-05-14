#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	getchar();

	while (n--) {
		string str;

		getline(cin, str);

		if ('a' <= str[0] && str[0] <= 'z') str[0] -= 32;

		cout << str << endl;
	}
	return 0;
}