#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<pair<int, string>> v;
	while (n--) {
		string name;
		int dd, mm, yyyy;
		cin >> name >> dd >> mm >> yyyy;
		v.push_back({yyyy * 10000 + mm * 100 + dd, name});
	}
	sort(v.begin(), v.end());

	cout << v[v.size() - 1].second << '\n' << v[0].second;

	return 0;
}