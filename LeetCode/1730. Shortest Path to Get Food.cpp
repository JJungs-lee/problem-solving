class Solution {
	const char FOOD = '#';
	const char EMPTY = 'O';
	const char WALL = 'X';
	pair<int, int> DIR[4] = {
	    {1, 0},
	    {-1, 0},
	    {0, 1},
	    {0, -1},
	};

public:
	int getFood(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		queue<pair<int, int>> q;

		for (int y = 0; y < m; ++y) {
			for (int x = 0; x < n; ++x) {
				if (grid[y][x] == '#') {
					q.push({y, x});
				}
			}
		}

		int res = 0;

		while (!q.empty()) {
			int size = q.size();
			res++;
			for (int i = 0; i < size; ++i) {
				auto [cur_y, cur_x] = q.front();
				q.pop();

				for (auto [dy, dx] : DIR) {
					int next_y = cur_y + dy;
					int next_x = cur_x + dx;

					if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n)
						continue;
					if (grid[next_y][next_x] == WALL)
						continue;
					if (grid[next_y][next_x] == '*')
						return res;
					q.push({next_y, next_x});
					grid[next_y][next_x] = WALL;
				}
			}
		}
		return -1;
	}
};