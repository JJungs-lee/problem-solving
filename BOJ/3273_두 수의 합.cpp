#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, num;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		v.push_back(num);
	}
	cin >> x;

	sort(begin(v), end(v));

	int l = 0, r = n - 1;
	int res = 0;

	while (l < r) {
		if (v[l] + v[r] == x) {
			res++;
			l++;
			r--;
			continue;
		}

		if (v[l] + v[r] < x)
			l++;
		else
			r--;
	}
	cout << res;

	return 0;
}