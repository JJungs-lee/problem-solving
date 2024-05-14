#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) break;

		a > b ? cout << "Yes" << endl : cout << "No" << endl;
	}

	return 0;
}
