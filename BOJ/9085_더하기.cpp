#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		int num;
		int res = 0;

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> num;
			res += num;
		}
		cout << res << '\n';
	}

	return 0;
}