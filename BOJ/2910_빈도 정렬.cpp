#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, c;
vector<pair<int, int>> v;  // cnt, num

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	int num;
	for (int i = 0; i < n; ++i) {
		cin >> num;

		bool flag = false;
		for (auto &iter : v) {
			if (iter.second == num) {
				iter.first++;
				flag = true;
				break;
			}
		}
		if (!flag)
			v.push_back({1, num});
	}

	stable_sort(v.begin(), v.end(), cmp);
	for (auto iter : v) {
		while (iter.first--)
			cout << iter.second << ' ';
	}
	return 0;
}