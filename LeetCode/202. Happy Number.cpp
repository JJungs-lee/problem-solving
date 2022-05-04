class Solution {
public:
	bool isHappy(int n) {
		int cur = n;
		unordered_set<int> hash;

		while (cur != 1) {
			int div_num = cur;
			int sum = 0;

			while (div_num) {
				sum += (div_num % 10) * (div_num % 10);
				div_num /= 10;
			}

			cur = sum;
			if (hash.find(cur) != end(hash))
				return false;

			hash.insert(cur);
		}
		return true;
	}
};