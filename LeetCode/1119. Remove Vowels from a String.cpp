class Solution {
public:
	string removeVowels(string s) {
		int i = 0;
		while (i < s.size()) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				s.replace(i, 1, "");
			} else {
				i++;
			}
		}
		return s;
	}
};