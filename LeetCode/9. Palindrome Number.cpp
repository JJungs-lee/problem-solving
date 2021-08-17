class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		string str = to_string(x);
		int len = str.size();
		for (int i = 0; i < len / 2; ++i) {
			if (str[i] != str[len - i - 1]) {
				return false;
			}
		}
		return true;
	}
};