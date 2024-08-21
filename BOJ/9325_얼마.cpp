#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;

	while (tc--) {
		int s, n;
		cin >> s >> n;

		while (n--) {
			int q, p;
			cin >> q >> p;
			s += q * p;
		}
		cout << s << '\n';
	}
	return 0;
}