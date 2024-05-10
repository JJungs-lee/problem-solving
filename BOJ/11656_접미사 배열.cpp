#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;
	vector<string> v;

	while (str.size()) {
		v.push_back(str);
		str = str.erase(0, 1);
	}
	sort(v.begin(), v.end());

	for (auto s : v)
		cout << s << '\n';
	return 0;
}