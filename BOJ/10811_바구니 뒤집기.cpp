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
	vector<int> v(n);

	for (int i = 0; i < n; ++i)
		v[i] = i + 1;

	for (int i = 0; i < m; ++i) {
		int start, end;
		cin >> start >> end;

		for (int j = 0; j <= (end - start) / 2; ++j) {
			swap(v[start + j - 1], v[end - j - 1]);
		}
	}

	for (int num : v)
		cout << num << ' ';

	return 0;
}