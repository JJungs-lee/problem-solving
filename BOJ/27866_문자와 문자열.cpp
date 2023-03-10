#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int i;

	cin >> str >> i;

	cout << str[i - 1];

	return 0;
}
