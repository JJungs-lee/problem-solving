class Solution {
public:
	bool backspaceCompare(string s, string t) {
		int s_idx = s.length() - 1;
		int t_idx = t.length() - 1;
		int skip_s = 0, skip_t = 0;

		while (s_idx >= 0 || t_idx >= 0) {
			while (s_idx >= 0) {
				if (s[s_idx] == '#') {
					s_idx--;
					skip_s++;
				} else if (skip_s) {
					s_idx--;
					skip_s--;
				} else {
					break;
				}
			}

			while (t_idx >= 0) {
				if (t[t_idx] == '#') {
					t_idx--;
					skip_t++;
				} else if (skip_t) {
					t_idx--;
					skip_t--;
				} else {
					break;
				}
			}

			if (s_idx >= 0 && t_idx >= 0 && t[t_idx] != s[s_idx])
				return false;
			if ((s_idx >= 0) != (t_idx >= 0))
				return false;
			s_idx--;
			t_idx--;
		}
		return true;
	}
};