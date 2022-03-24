class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		unordered_map<int, int> hash_table;

		for (int i = 0; i < numbers.size(); ++i) {
			int diff = target - numbers[i];
			auto iter = hash_table.find(diff);

			if (iter != hash_table.end()) {
				return {hash_table[diff] + 1, i + 1};
			} else {
				hash_table[numbers[i]] = i;
			}
		}
		return {};
	}
};