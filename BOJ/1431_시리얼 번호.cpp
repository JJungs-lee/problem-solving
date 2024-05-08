#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;

bool cmp(const string &a, const string &b) {
	int a_size = a.size();
	int b_size = b.size();

	if (a_size != b_size)
		return a_size < b_size;

	int a_sum = 0, b_sum = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (isdigit(a[i]))
			a_sum += a[i] - '0';
		if (isdigit(b[i]))
			b_sum += b[i] - '0';
	}
	if (a_sum != b_sum)
		return a_sum < b_sum;
	return a < b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	string str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);

	for (auto s : v)
		cout << s << '\n';

	return 0;
}