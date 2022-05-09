class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string res;

		for (auto iter = s.rbegin(); iter != s.rend(); iter++) {
			if (*iter == '-')
				continue;

			if (res.size() % (k + 1) == k)
				res += '-';

			res += toupper(*iter);
		}

		reverse(begin(res), end(res));

		return res;
	}
};