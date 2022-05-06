class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int low_idx = lower_bound(begin(nums), end(nums), target) - begin(nums);
		int high_idx = upper_bound(begin(nums), end(nums), target) - begin(nums);

		if (low_idx >= nums.size() || nums[low_idx] != target || nums[high_idx - 1] != target)
			return {-1, -1};

		return {low_idx, high_idx - 1};
	}
};