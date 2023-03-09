#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	unordered_map<string, int> hash;
	vector<string> v;
	float sum = 0;

	while (getline(cin, str)) {
		sum++;
		auto find = hash.find(str);
		if (find != hash.end()) {
			find->second++;
		} else {
			hash.insert({str, 1});
			v.push_back(str);
		}
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i) {
		cout << fixed;
		cout.precision(4);
		cout << v[i] << ' ' << hash.find(v[i])->second * 100.0 / sum << '\n';
	}

	return 0;
}
