class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		// move all the nonzero elements advance
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		for (; j < nums.size(); j++) {
			nums[j] = 0;
		}
	}
/*
	void moveZeroes(vector<int>& nums) {
		int zero_idx = 0;
		int non_zero_idx = 0;
		int size = nums.size();

		if (size == 1) {
			return;
		}

		while (true) {
			for (int i = zero_idx; i < size; ++i) {
				if (nums[i] == 0) {
					zero_idx = i;
					non_zero_idx = i;
					break;
				}
			}
			for (int i = non_zero_idx; i < size; ++i) {
				if (nums[i] != 0) {
					non_zero_idx = i;
					break;
				}
			}

			swap(nums[zero_idx], nums[non_zero_idx]);

			zero_idx++;

			if (zero_idx > non_zero_idx) {
				break;
			}
		}
	}
*/

};