class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> hash_table;

		for (int n : nums) {
			if (hash_table.find(n) != hash_table.end())
				return true;
			else
				hash_table.insert(n);
		}
		return false;
	}
};