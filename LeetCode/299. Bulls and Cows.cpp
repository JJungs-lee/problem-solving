class Solution {
public:
	string getHint(string secret, string guess) {
		string ret;
		int cnt_a[10] = { 0, };
		int cnt_b[10] = { 0, };
		int match_a = 0;
		int match_b = 0;

		for (int i = 0; i < secret.size(); ++i) {
			if (secret[i] == guess[i]) {
				match_a++;
			} else {
				cnt_a[secret[i] - '0']++;
				cnt_b[guess[i] - '0']++;
			}
		}

		for (int i = 0; i < 10; ++i) {
			match_b += min(cnt_a[i], cnt_b[i]);
		}

		return to_string(match_a) + "A" + to_string(match_b) + "B";
	}
};