class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int res = 0;
		int sum = 0;
		for (int n : nums) {
			if (!n) {
				res = max(res, sum);
				sum = 0;
			} else {
				sum += n;
			}
		}

		return max(res, sum);
	}
};