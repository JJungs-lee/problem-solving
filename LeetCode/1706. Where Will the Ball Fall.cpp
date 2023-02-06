class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<int> res;

		for (int x = 0; x < n; ++x) {
			int cur_x = x;

			for (int y = 0; y < m; ++y) {
				int next_x = cur_x + grid[y][cur_x];

				if (next_x < 0 || next_x >= n || grid[y][next_x] != grid[y][cur_x]) {
					cur_x = -1;
					break;
				}
				cur_x = next_x;
			}
			res.push_back(cur_x);
		}
		return res;
	}
};
