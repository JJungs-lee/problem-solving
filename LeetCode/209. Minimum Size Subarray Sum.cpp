class Solution {
public:
	int minSubArrayLen(int target, vector<int>& nums) {
		int left = 0;
		int sum = 0;
		int res = INT_MAX;

		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];

			while (sum >= target) {
				res = min(res, i + 1 - left);
				sum -= nums[left++];
			}
		}
		return res == INT_MAX ? 0 : res;
	}
};