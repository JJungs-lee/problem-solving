#include <iostream>
#include <map>
#include <string>
using namespace std;

static map<string, pair<int, int>> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	m["black"] = {0, 1};
	m["brown"] = {1, 10};
	m["red"] = {2, 100};
	m["orange"] = {3, 1000};
	m["yellow"] = {4, 10000};
	m["green"] = {5, 100000};
	m["blue"] = {6, 1000000};
	m["violet"] = {7, 10000000};
	m["grey"] = {8, 100000000};
	m["white"] = {9, 1000000000};

	long long res = 0;
	string str;
	for (int i = 0; i < 3; ++i) {
		cin >> str;
		if (i != 2) {
			res *= 10;
			res += m[str].first;
		} else {
			res *= m[str].second;
		}
	}
	cout << res << '\n';

	return 0;
}