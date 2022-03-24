class Solution {
public:
	int subtractProductAndSum(int n) {
		int sum = 0;
		int mul = 1;

		while (n) {
			int cur = n % 10;
			sum += cur;
			mul *= cur;
			n /= 10;
		}
		return mul - sum;
	}
};