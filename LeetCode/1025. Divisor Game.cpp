class Solution {
public:
	bool divisorGame(int n) {
		int x = 1;
		bool is_alice_win = false;

		while (x < n) {
			while (n % x != 0) {
				x++;
			}
			n = n - x;
			is_alice_win ^= true;
			x = 1;
		}

		return is_alice_win;
	}
};