#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;

		int c;
		double g;

		int sum_c = 0;
		double sum_g = 0.0;
		for (int i = 0; i < n; ++i) {
			cin >> c >> g;
			sum_c += c;
			sum_g += (g * c);
		}
		cout << fixed;
		cout.precision(1);
		cout << sum_c << " " << sum_g / sum_c << '\n';
	}
	return 0;
}