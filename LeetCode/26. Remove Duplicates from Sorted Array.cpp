class Solution {
public:
int removeDuplicates(vector<int>& nums) {
	int cur_num = -10001;
	int push_idx = 0;
	for (int i = 0; i < nums.size(); ++i) {
		if (cur_num == nums[i])
			continue;

		cur_num = nums[i];
		nums[push_idx] = nums[i];
		push_idx++;
	}
	return push_idx;
}
};