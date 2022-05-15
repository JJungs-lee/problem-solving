class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int push_idx = 0;
		int cur_nums = -100000;
		int check_twice = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == cur_nums) {
				if (check_twice < 2) {
					nums[push_idx++] = nums[i];
					check_twice++;
				}
				continue;
			}
			nums[push_idx++] = nums[i];
			cur_nums = nums[i];
			check_twice = 1;
		}
		return push_idx;
	}
};