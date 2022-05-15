class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<vector<int>> dp(34);
		// 0번
		dp[0].push_back(1);
		// 1번
		dp[1].push_back(1);
		dp[1].push_back(1);

		for (int row = 2; row <= rowIndex; ++row) {
			for (int i = 0; i <= row; ++i) {
				if (i == 0 || i == row)
					dp[row].push_back(1);
				else
					dp[row].push_back(dp[row - 1][i] + dp[row - 1][i - 1]);
			}
		}

		return dp[rowIndex];
	}
};