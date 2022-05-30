class Solution {
public:
	string removeOuterParentheses(string s) {
		int open_cnt = 0;
		int close_cnt = 0;

		string res;
		string cur;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(')
				open_cnt++;
			else if (s[i] == ')')
				close_cnt++;
			cur += s[i];

			if (open_cnt == close_cnt) {
				cur.erase(cur.end() - 1);
				cur.erase(cur.begin());
				res += cur;

				open_cnt = 0;
				close_cnt = 0;
				cur.clear();
			}
		}
		return res;
	}
};
