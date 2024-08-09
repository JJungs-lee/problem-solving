#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> hash_table;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, l;
	cin >> k >> l;

	string num;
	for (int i = 0; i < l; ++i) {
		cin >> num;
		hash_table[num] = i;
	}
	vector<pair<string, int>> v(hash_table.begin(), hash_table.end());
	sort(v.begin(), v.end(), [](auto& a, auto& b) { return a.second < b.second; });

	int end = min((int)v.size(), k);
	for (int i = 0; i < end; ++i)
		cout << v[i].first << '\n';
	return 0;
}