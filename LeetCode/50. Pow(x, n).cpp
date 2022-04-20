class Solution {
public:
	double myPow(double x, int n) {
		double ret = 1;

		while (n) {
			if (n % 2) {
				if (n > 0)
					ret *= x;
				else
					ret /= x;
			}
			x *= x;
			n /= 2;
		}
		return ret;
	}
};