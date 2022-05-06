class Solution {
public:
	int mySqrt(int x) {
		int start = 0;
		int end = 50000;
		unsigned long long mid;

		while (start < end) {
			mid = (start + end) / 2;

			if (mid * mid == x) {
				return mid;
			}

			if (mid * mid > INT_MAX) {
				end = mid - 1;
			} else if (mid * mid < x) {
				start = mid + 1;
			} else {
				end = mid;
			}
		}

		if (mid * mid > x)
			return mid - 1;

		return mid;
	}
};