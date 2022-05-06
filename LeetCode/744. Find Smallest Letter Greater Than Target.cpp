class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		auto iter = upper_bound(begin(letters), end(letters), target);
		if (iter == end(letters)) {
			return letters[0];
		}
		return *iter;
	}
};