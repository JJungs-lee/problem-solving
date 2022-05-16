class Solution {
	string letter[10] = {
	    "", "", "abc",
	    "def", "ghi", "jkl",
		"mno", "pqrs", "tuv", "wxyz"};

public:
	vector<string> letterCombinations(string digits) {
		int len = digits.size();
		vector<string> res;

		if (!len)
			return res;

		queue<pair<string, int>> q;
		q.push({"", 0});

		while (!q.empty()) {
			auto [cur_str, idx] = q.front();
			q.pop();

			if (idx == digits.size()) {
				res.push_back(cur_str);
				continue;
			}

			int letter_idx = digits[idx] - '0';

			for (int i = 0; i < letter[letter_idx].size(); ++i) {
				q.push({cur_str + letter[letter_idx][i], idx + 1});
			}
		}
		return res;
	}
};