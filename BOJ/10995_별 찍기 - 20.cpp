#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string line;

	for (int i = 0; i < n; ++i) {
		line += "* ";
	}

	for (int i = 0; i < n; ++i) {
		if (i & 1)
			cout << " " << line << '\n';
		else
			cout << line << '\n';
	}

	return 0;
}