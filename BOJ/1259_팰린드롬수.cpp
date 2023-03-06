#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string num;
	while (true) {
		cin >> num;
		if (num.size() == 1 && num[0] == '0')
			break;

		bool flag = true;
		for (unsigned int i = 0; i < num.size() / 2; ++i) {
			if (num[i] != num[num.size() - 1 - i]) {
				cout << "no\n";
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes\n";
	}

	return 0;
}