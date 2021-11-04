class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		do {
			vector<int> v;
			for (int i : nums) {
				v.push_back(i);
			}
			res.push_back(v);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};