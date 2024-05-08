#include <algorithm>
#include <iostream>
using namespace std;

pair<int, int> p[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);
	for (int i = 0; i < n; ++i) {
		cout << p[i].first << ' ' << p[i].second << '\n';
	}

	return 0;
}