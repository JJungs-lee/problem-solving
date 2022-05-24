class Solution {
public:
	bool areNumbersAscending(string s) {
		string str_number;
		int before_num = -1;
		for (int i = 0; i < s.size(); ++i) {
			if (isdigit(s[i]))
				str_number += s[i];


			if ((s[i] == ' ' || i == s.size() - 1) && str_number.size()) {
				int cur_num = stoi(str_number);

				if (before_num < cur_num)
					before_num = cur_num;
				else
					return false;
				str_number.clear();
			}
		}
		return true;
	}
};