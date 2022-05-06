/*
 * 1st solution
 * Time complexity: O(N)
 * Space complexity: O(1)
 */

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int max_sum = nums[0];
		int cur_sum = nums[0];

		for (int i = 1; i < nums.size(); ++i) {
			int n = nums[i];

			cur_sum = max(n, cur_sum + n);
			max_sum = max(max_sum, cur_sum);
		}
		return max_sum;
	}
};

/*
 * 2nd solution
 * Time complexity: O(N⋅logN)
 * Space complexity: O(logN)
 */
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		return findBestSubArray(nums, 0, nums.size() - 1);
	}

	int findBestSubArray(vector<int>& nums, int left, int right) {
		if (left > right)
			return INT_MIN;

		int mid = (left + right) / 2;
		int left_max_sum = 0;
		int right_max_sum = 0;
		int cur = 0;

		for (int i = mid - 1; i >= left; --i) {
			cur += nums[i];
			left_max_sum = max(left_max_sum, cur);
		}

		cur = 0;
		for (int i = mid + 1; i <= right; ++i) {
			cur += nums[i];
			right_max_sum = max(right_max_sum, cur);
		}

		int best_combined_sum = left_max_sum + nums[mid] + right_max_sum;

		int left_half = findBestSubArray(nums, left, mid - 1);
		int righ_half = findBestSubArray(nums, mid + 1, right);

		return max(best_combined_sum, max(left_half, righ_half));
	}
};