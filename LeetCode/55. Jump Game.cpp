// #1 -> O(N^2) TL
class Solution {
	bool dfs(vector<int>& nums, int idx) {
		if (idx == nums.size() - 1)
			return true;

		for (int i = nums[idx]; i > 0; --i) {
			if (idx + i >= nums.size())
				continue;

			if (dfs(nums, idx + i))
				return true;
		}
		return false;
	};

public:
	bool canJump(vector<int>& nums) {
		return dfs(nums, 0);
	}
};