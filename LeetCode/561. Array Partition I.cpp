class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int res = 0;

		sort(begin(nums), end(nums));

		for (int i = 0; i < nums.size(); ++i) {
			if ((i & 1) == 0) {
				res += nums[i];
			}
		}
		return res;
	}
};