#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	int i = 1;
	while (tc--) {
		int a, b;
		cin >> a >> b;
		cout << "Case " << i++ << ": " << a + b << '\n';
	}

	return 0;
}