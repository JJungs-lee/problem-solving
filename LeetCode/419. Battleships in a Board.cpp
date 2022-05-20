class Solution {
   public:
	int countBattleships(vector<vector<char>>& board) {
		int res = 0;
		int m = board.size();
		int n = board[0].size();

		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (board[y][x] == '.')
					continue;

				board[y][x] = '.';
				res++;

				int temp_y = y + 1;
				int temp_x = x + 1;

				while (temp_y < m && board[temp_y][x] == 'X') {
					board[temp_y][x] = '.';
					temp_y++;
				}
				while (temp_x < n && board[y][temp_x] == 'X') {
					board[y][temp_x] = '.';
					temp_x++;
				}
			}
		}
		return res;
	}
};