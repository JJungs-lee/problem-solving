class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		int j = nums.size() - 1;
		int match_cnt = 0;

		while (i <= j) {
			while (j > 0 && nums[j] == val) {
				j--;
				match_cnt++;
			}

			if (nums[i] == val) {
				match_cnt++;
				swap(nums[i], nums[j]);
				j--;
			} else {
				i++;
			}
		}
		return nums.size() - match_cnt;
	}
};