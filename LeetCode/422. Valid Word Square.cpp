class Solution {
public:
	bool validWordSquare(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i) {
			if (words[i].size() > words.size())
				return false;

			for (int j = 0; j < words[i].size(); ++j) {
				if (words[i][j] != words[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
};