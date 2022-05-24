class Solution {
public:
	int missingElement(vector<int>& nums, int k) {
		int res = -1;

		for (int i = 0; i < nums.size() - 1; ++i) {
			auto lower_num = *lower_bound(begin(nums), end(nums), nums[i]);
			auto upper_num = *upper_bound(begin(nums), end(nums), nums[i]);

			int existed_count = upper_num - lower_num - 1;
			if (k <= existed_count) {
				return lower_num + k;
			} else {
				k -= existed_count;
			}
		}
		if (res == -1)
			return nums[nums.size() - 1] + k;

		return res;
	}
};