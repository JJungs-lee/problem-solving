class Solution {
	const int INF = INT_MAX;
	const int WALL = -1;
	const int GATE = 0;

	const pair<int, int> DIR[4] = {
	    {0, 1},
	    {0, -1},
	    {1, 0},
	    {-1, 0},
	};

	void bfs(vector<vector<int>>& rooms) {
		queue<pair<int, int>> q;
		// find gate location

		for (int y = 0; y < rooms.size(); ++y) {
			for (int x = 0; x < rooms[y].size(); ++x) {
				if (rooms[y][x] == GATE)
					q.push({y, x});
			}
		}

		int m = rooms.size();
		int n = rooms.size() == 0 ? 0 : rooms[0].size();

		while (!q.empty()) {
			auto [cur_y, cur_x] = q.front();
			q.pop();
			for (auto d : DIR) {
				int move_y = cur_y + d.first;
				int move_x = cur_x + d.second;

				if (move_y < 0 || move_x < 0 || move_y >= m || move_x >= n)
					continue;

				if (rooms[move_y][move_x] == WALL || rooms[move_y][move_x] != INF)
					continue;
				q.push({move_y, move_x});
				rooms[move_y][move_x] = rooms[cur_y][cur_x] + 1;
			}
		}
	}

public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		bfs(rooms);
	}
};