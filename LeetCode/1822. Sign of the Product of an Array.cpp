class Solution {
public:
	int arraySign(vector<int>& nums) {
		bool flag = true;

		for (int n : nums) {
			if (n == 0)
				return 0;
			if (n < 0)
				flag ^= 1;
		}

		return flag ? 1 : -1;
	}
};