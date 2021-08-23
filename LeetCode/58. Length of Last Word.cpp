class Solution {
public:
	int lengthOfLastWord(string s) {
		int res = 0;
		int idx = s.size() - 1;

		while (s[idx] == ' ')
			idx--;

		for (; idx > -1; --idx) {
			if (s[idx] == ' ')
				break;
			else
				res++;
		}
		return res;
	}
};