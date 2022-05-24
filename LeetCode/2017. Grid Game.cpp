class Solution {
public:
	long long gridGame(vector<vector<int>>& grid) {
		int col_size = grid[0].size();
		long long upper_sum = 0;
		long long lower_sum = 0;
		long long res = 0;
		for (int i = 1; i < col_size; ++i) {
			upper_sum += grid[0][i];
		}
		res = upper_sum;
		for (int i = 1; i < col_size; ++i) {
			upper_sum -= grid[0][i];
			lower_sum += grid[1][i - 1];
			res = min(res, max(upper_sum, lower_sum));
		}
		return res;
	}
};