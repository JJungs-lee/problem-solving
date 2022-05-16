class Solution {
	const int MAX_DIR = 8;
	const int WALL = 1;
	pair<int, int> DIR[8] = {
	    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

public:
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		int n = grid.size();

		queue<pair<pair<int, int>, int>> q;
		if (grid[0][0] == 0) {
			q.push({{0, 0}, 1});
			grid[0][0] = WALL;
		}

		while (!q.empty()) {
			auto [cur_y, cur_x] = q.front().first;
			int len = q.front().second;
			q.pop();

			if (cur_y == n - 1 && cur_x == n - 1) {
				return len;
			}

			for (int i = 0; i < MAX_DIR; ++i) {
				int dy = cur_y + DIR[i].first;
				int dx = cur_x + DIR[i].second;

				if (dy < 0 || dx < 0 || dy >= n || dx >= n)
					continue;

				if (!grid[dy][dx]) {
					q.push({{dy, dx}, len + 1});
					grid[dy][dx] = WALL;
				}
			}
		}

		return -1;
	}
};