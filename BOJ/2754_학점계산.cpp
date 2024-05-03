#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	cout.setf(ios::fixed, ios::floatfield);
	cout.precision(1);

	cout << ((str[0] < 66 ? 4 : str[0] < 67 ? 3 : str[0] < 68 ? 2 : str[0] < 69 ? 1 : 0)
		+ (str[1] == '+' ? 0.3 : str[1] == '-' ? -0.3 : 0));
	return 0;
}
