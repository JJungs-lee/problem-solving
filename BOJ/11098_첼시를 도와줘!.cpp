#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int testCase;

	cin >> testCase;
	while (testCase--) {
		vector<pair<int, string> > v;
		int n;
		int money;
		string str;
		cin >> n;

		for (int i = 0; i < n; ++i) {
			cin >> money >> str;
			v.push_back(make_pair(money, str));
		}
		sort(v.begin(), v.end());

		cout << v[n - 1].second << endl;
	}
	return 0;
}