#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	unordered_set<string> h;

	string str;
	while (n--) {
		cin >> str;
		h.insert(str);
	}

	vector<string> v;
	while (m--) {
		cin >> str;
		if (h.find(str) != h.end()) {
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (string str : v)
		cout << str << '\n';

	return 0;
}
