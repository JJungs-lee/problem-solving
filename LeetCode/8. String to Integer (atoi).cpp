class Solution {
public:
	int myAtoi(string s) {
		int i = 0, sign = 1;
		int ret = 0;
		int len = s.size();

		if (len == 0)
			return 0;

		while (s[i] == ' ')
			i++;

		if (s[i] == '-' || s[i] == '+')
			sign = (s[i++] == '-') ? -1 : 1;

		for (; i < len && '0' <= s[i] && s[i] <= '9'; ++i) {
			if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && s[i] - '0' > 7))
				return (sign == 1) ? INT_MAX : INT_MIN;

			ret = ret * 10 + (s[i] - '0');
		}

		return sign * ret;
	}
};