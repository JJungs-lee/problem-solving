#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		cin >> a >> b;

		// (꼭짓점의 수) - (모서리의 수) + (면의 수) = 2
		cout << 2 - a + b << '\n';
	}

	return 0;
}