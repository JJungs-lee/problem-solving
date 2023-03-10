#include <iostream>
#include <vector>
using namespace std;

#define MAN 1
#define GIRL 2

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> v;

	cin >> n;
	v.resize(n);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int sex, idx;
		cin >> sex >> idx;

		if (sex == MAN) {
			for (int i = idx - 1, mul = 2; i < n; mul++) {
				v[i] ^= 1;
				i = (idx * mul) - 1;
			}
		} else {
			int start = idx - 1, end = idx - 1;
			while (true) {
				int next_s = start - 1;
				int next_e = end + 1;
				if (next_s > -1 && next_e < n) {
					if (v[next_s] != v[next_e]) {
						break;
					}
					start--;
					end++;
				} else {
					break;
				}
			}
			for (int i = start; i <= end; ++i)
				v[i] ^= 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << v[i] << ' ';
		if (i % 20 == 19)
			cout << '\n';
	}

	return 0;
}
