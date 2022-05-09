class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> chars(128);
		int left = 0;
		int right = 1;
		int res = 1;

		if (s.size() == 0)
			return 0;

		chars[s[left]]++;
		while (right < s.size()) {
			while (right < s.size() && !chars[s[right]]) {
				chars[s[right]]++;
				right++;
			}
			res = max(res, right - left);
			chars[s[left]]--;
			left++;
		}
		return res;
	}
};