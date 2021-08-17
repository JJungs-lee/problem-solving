class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		vector<int> ret;
		int end_idx = digits.size() - 1;
		int carry = 1;

		for (int i = end_idx; i >= 0; i--) {
			digits[i] += carry;
			carry = digits[i] / 10;
			ret.push_back(digits[i] % 10);
		}
		if (carry) {
			ret.push_back(carry);
		}
		reverse(ret.begin(), ret.end());

		return ret;
	}
};