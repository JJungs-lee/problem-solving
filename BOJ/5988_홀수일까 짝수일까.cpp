#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	string str;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> str;
		(str.back()-'0') % 2 == 0 ? cout << "even" << endl : cout << "odd" << endl;
	}
	return 0;
}