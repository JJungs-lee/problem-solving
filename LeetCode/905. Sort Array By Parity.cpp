class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		int swap_idx = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (!(nums[i] & 1)) {
				swap(nums[i], nums[swap_idx++]);
			}
		}
		return nums;
	}
};