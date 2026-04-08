// #2
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int target_idx = nums.size() - 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (target_idx <= i + nums[i]) {
                target_idx = i;
            }
        }
        return target_idx == 0;
    }
};

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