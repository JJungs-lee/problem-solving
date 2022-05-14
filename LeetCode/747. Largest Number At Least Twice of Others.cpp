class Solution {
public:
	int dominantIndex(vector<int>& nums) {
		int max_first_num = 0;
		int max_second_num = 0;
		int max_idx = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > max_first_num) {
				max_idx = i;
				max_second_num = max_first_num;
				max_first_num = nums[i];
			} else if (nums[i] > max_second_num)
				max_second_num = nums[i];
		}
		return max_first_num >= max_second_num * 2 ? max_idx : -1;
	}
};