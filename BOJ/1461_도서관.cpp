#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<int> v;

	int count = 0;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		v.push_back(num);
		if (v[i] < 0)
			count++;
	}

	sort(v.begin(), v.end());

	int res = 0;
	for (int i = 0; i < count; i += m)
		res += abs(v[i] * 2);
	for (int i = n - 1; i >= count; i -= m)
		res += abs(v[i] * 2);

	res -= max(abs(v[n - 1]), abs(v[0]));

	cout << res;

	return 0;
}
