#include <iostream>
using namespace std;

int main() {
	string str;
	char arr[101];

	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] >= 'a' && str[i] <= 'z')
			arr[i] = str[i] - 32;
		else
			arr[i] = str[i] + 32;
	}

	for (int i = 0; i < str.size(); ++i) {
		cout << arr[i];
	}
	return 0;
}