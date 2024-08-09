#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	int y = 0, k = 0;
	int n1, n2;
	while (t--) {
		for (int i = 0; i < 9; ++i) {
			cin >> n1 >> n2;
			y += n1;
			k += n2;
		}

		if (y > k)
			cout << "Yonsei\n";
		else if (y < k)
			cout << "Korea\n";
		else
			cout << "Draw\n";
	}

	return 0;
}