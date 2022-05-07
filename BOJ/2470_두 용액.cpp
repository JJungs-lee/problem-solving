#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, num;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		v.push_back(num);
	}
	sort(begin(v), end(v));

	int l = 0, r = n - 1;
	pair<int, pair<int, int>> pos;
	pos.first = INT_MAX;

	while (l < r) {
		int sum = v[l] + v[r];
		if (abs(sum) < pos.first) {
			pos.first = abs(sum);
			pos.second.first = l;
			pos.second.second = r;
		}

		if (sum < 0) {
			l++;
		} else {
			r--;
		}
	}

	cout << v[pos.second.first] << " " << v[pos.second.second] << "\n";

	return 0;
}