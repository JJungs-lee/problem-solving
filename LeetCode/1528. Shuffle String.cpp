class Solution {
public:
	string restoreString(string s, vector<int>& indices) {
		string str(s.size(), 'a');
		int i = 0;
		for (int x : indices)
			str[x] = s[i++];

		return str;
	}
};