class Solution {
public:
	int subsetXORSum(vector<int>& nums) {
		int res = 0;
		int size = nums.size();

		for (int i = 0; i < (1 << size); ++i) {
			int sum = 0;
			for (int j = 0; j < size; ++j) {
				if ((i >> j) & 1) {
					sum ^= nums[j];
				}
			}
			res += sum;
		}
		return res;
	}
};