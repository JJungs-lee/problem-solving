#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(const string a, const string b) {
	if (a.size() == b.size()) {
		for (unsigned int i = 0; i < a.size(); ++i) {
			if (a[i] == b[i])
				continue;
			else
				return a[i] < b[i];
		}
	} else {
		return a.size() < b.size();
	}
	return false;
}

string delete_first_zero(string &str) {
	if (str.size() > 1) {
		for (auto iter = str.begin(); iter != str.end();) {
			if (*iter == '0')
				iter = str.erase(iter);
			else
				break;
		}
	}
	if (str.size() == 0)
		return "0";

	return str;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> res;

	while (n--) {
		string s;
		string num;
		bool flag = false;

		cin >> s;

		for (unsigned int i = 0; i < s.size(); ++i) {
			if (isdigit(s[i])) {
				num += s[i];
				flag = true;
			} else if (flag) {
				res.push_back(delete_first_zero(num));
				num.clear();
				flag = false;
			}
		}
		if (flag)
			res.push_back(delete_first_zero(num));
	}

	sort(res.begin(), res.end(), cmp);

	for (auto num : res)
		cout << num << '\n';

	return 0;
}