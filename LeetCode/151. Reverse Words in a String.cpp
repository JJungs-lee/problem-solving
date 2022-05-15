class Solution {
public:
	string reverseWords(string s) {
		string res;
		string word;

		for (char c : s) {
			if (c == ' ') {
				if (res.size() && word.size())
					res = " " + res;
				res = (word + res);

				word.clear();

			} else {
				word += c;
			}
		}
		if (res.size() && word.size())
			res = (word + " ") + res;
		else
			res = word + res;
		return res;
	}
};