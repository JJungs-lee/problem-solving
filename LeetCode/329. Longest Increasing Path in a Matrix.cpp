class Solution {
public:
	struct Point {
		int y, x;
	};

	static const int DIR = 4;
	int dx[DIR] = {1, -1, 0, 0};
	int dy[DIR] = {0, 0, 1, -1};
	int m;
	int n;

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		m = matrix.size();
		n = matrix[0].size();

		int ret = 0;
		vector<vector<int>> dp(m, vector<int>(n, 0));

		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				ret = max(ret, dfs(matrix, dp, y, x));
			}
		}
		return ret;
	}

	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int y, int x) {
		if (dp[y][x] != 0)
			return dp[y][x];

		for (int i = 0; i < DIR; ++i) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (next_y >= 0 && next_x >= 0 && next_y < m && next_x < n) {
				if (matrix[y][x] < matrix[next_y][next_x])
					dp[y][x] = max(dp[y][x], dfs(matrix, dp, next_y, next_x));
			}
		}
		return ++dp[y][x];
	}
};