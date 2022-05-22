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

	int sum = 0;
	vector<int> sum_v;
	vector<int> v(100001);
	sum_v.push_back(0);

	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
		sum_v.push_back(sum);
	}

	while (m--) {
		int first, second;
		cin >> first >> second;
		cout << sum_v[second] - sum_v[first - 1] << '\n';
	}

	return 0;
}