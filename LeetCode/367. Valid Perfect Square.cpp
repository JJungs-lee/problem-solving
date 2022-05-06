class Solution {
public:
	bool isPerfectSquare(int num) {
		int start = 0;
		int end = 46875;

		if (num == 1)
			return true;

		while (start < end) {
			unsigned long long mid = (start + end) / 2;
			unsigned long long pow2 = mid * mid;

			if (pow2 > INT_MAX) {
				end = mid;
				continue;
			}

			if (pow2 == num)
				return true;

			if (pow2 < num)
				start = mid + 1;
			else
				end = mid;
		}
		return false;
	}
};