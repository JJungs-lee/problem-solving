class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hash_table;

		for (int i = 0; i < nums.size(); ++i) {
			int diff = target - nums[i];
			auto iter = hash_table.find(diff);

			if (iter != hash_table.end()) {
				return { hash_table[diff], i };
			} else {
				hash_table[nums[i]] = i;
			}
		}
		return {};
	}
};