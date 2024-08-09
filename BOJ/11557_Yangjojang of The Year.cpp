#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;

	cin >> t;
	while (t--) {
		int n;

		cin >> n;
		string name, res;
		int count, max_count = -1;
		for (int i = 0; i < n; ++i) {
			cin >> name >> count;
			if (max_count < count) {
				res = name;
				max_count = count;
			}
		}
		cout << res << '\n';
	}

	return 0;
}