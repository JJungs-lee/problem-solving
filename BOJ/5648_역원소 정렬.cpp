#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<long long> v(n);
	string str;

	for (int i = 0; i < n; ++i) {
		cin >> str;
		reverse(str.begin(), str.end());
		v[i] = stoll(str);
	}
	sort(v.begin(), v.end());

	for (auto i : v)
		cout << i << '\n';

	return 0;
}