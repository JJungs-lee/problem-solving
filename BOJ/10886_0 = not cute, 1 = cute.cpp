#include <cstring>
#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	int ret = 0;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		ret += num;
	}
	cout << "Junhee is ";
	(n / 2) < ret ? cout << "cute!" << '\n' : cout << "not cute!" << '\n';

	return 0;
}
