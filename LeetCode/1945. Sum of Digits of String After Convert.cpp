class Solution {
public:
	int transform(int num) {
		int sum = 0;
		while (num) {
			sum += num % 10;
			num /= 10;
		}
		return sum;
	}
	int convertAndTransform(string &s) {
		int sum = 0;
		for (char c : s) {
			sum += transform(c - 'a' + 1);
		}
		return sum;
	}
	int getLucky(string s, int k) {
		int ret = convertAndTransform(s);
		for (int i = 1; i < k; ++i) {
			ret = transform(ret);
		}
		return ret;
	}
};