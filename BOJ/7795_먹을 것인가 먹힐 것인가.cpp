#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int tc;
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while (tc--) {
		cin >> n >> m;

		vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int res = 0;
		int a_idx = a.size() - 1;
		int b_idx = b.size() - 1;
		while (true) {
			if (a_idx < 0 || b_idx < 0)
				break;
			if (a[a_idx] > b[b_idx]) {
				res += b_idx + 1;
				a_idx--;
			} else {
				b_idx--;
			}
		}
		cout << res << '\n';
	}
	return 0;
}