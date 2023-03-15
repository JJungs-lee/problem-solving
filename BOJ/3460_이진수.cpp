#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int num;
		cin >> num;

		for (int i = 0; num > 0; ++i) {
			if (num & 1) 
				cout << i << ' ';
			num /= 2;
		}
		cout << '\n';
	}

	return 0;
}