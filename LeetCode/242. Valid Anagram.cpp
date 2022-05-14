class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size())
			return false;

		array<int, 26> arr;
		arr.fill(0);

		for (int i = 0; i < s.size(); ++i) {
			arr[s[i] - 'a']++;
		}

		for (int i = 0; i < t.size(); ++i) {
			arr[t[i] - 'a']--;
			if (arr[t[i] - 'a'] < 0)
				return false;
		}
		return true;
	}
};