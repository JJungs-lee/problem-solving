class Solution {
public:
	string addBinary(string a, string b) {
		string res;

		int carry = 0;
		int a_idx = a.size() - 1;
		int b_idx = b.size() - 1;

		while (carry || a_idx >= 0 || b_idx >= 0) {
			int sum = 0;

			if (a_idx >= 0) {
				sum += (a[a_idx] - '0');
				a_idx--;
			}

			if (b_idx >= 0) {
				sum += (b[b_idx] - '0');
				b_idx--;
			}

			if (carry) {
				sum += carry;
				carry = 0;
			}

			if (sum >= 2) {
				carry = 1;
				res += sum - 2 + '0';
			} else {
				res += sum + '0';
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};