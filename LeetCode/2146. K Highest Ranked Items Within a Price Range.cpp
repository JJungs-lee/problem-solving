class Solution {
	struct PriceData {
		int row;
		int col;
		int dis;
		int price;
	};

	struct cmp {
		bool operator()(PriceData& a, PriceData& b) {
			if (a.dis != b.dis)
				return a.dis > b.dis;
			else if (a.price != b.price)
				return a.price > b.price;
			else if (a.row != b.row)
				return a.row > b.row;
			else if (a.col != b.col)
				return a.col > b.col;
			return false;
		};
	};

	pair<int, int> DIR[4] = {
	    {0, 1},
	    {0, -1},
	    {1, 0},
	    {-1, 0},
	};

public:
	vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
		int m = grid.size();
		int n = grid[0].size();
		int min_price = pricing[0];
		int max_price = pricing[1];

		int dist = 0;
		int cur_price = grid[start[0]][start[1]];

		queue<pair<int, int>> q;
		priority_queue<PriceData, vector<PriceData>, cmp> pq;  // pos, distance

		q.push({start[0], start[1]});
		if (min_price <= cur_price && cur_price <= max_price) {
			pq.push({start[0], start[1], dist, cur_price});
			grid[start[0]][start[1]] = 0;
		}

		while (!q.empty()) {
			dist++;
			int q_size = q.size();

			for (int i = 0; i < q_size; ++i) {
				auto [cur_y, cur_x] = q.front();
				q.pop();

				for (int i = 0; i < 4; ++i) {
					int next_y = cur_y + DIR[i].first;
					int next_x = cur_x + DIR[i].second;

					if (next_y >= 0 && next_x >= 0 && next_y < m && next_x < n) {
						cur_price = grid[next_y][next_x];

						if (!cur_price)
							continue;

						if (min_price <= cur_price && cur_price <= max_price) {
							pq.push({next_y, next_x, dist + 1, cur_price});
						}
						q.push({next_y, next_x});
						grid[next_y][next_x] = 0;
					}
				}
			}
		}
		vector<vector<int>> res;
		while (k--) {
			if (pq.empty())
				break;
			res.push_back({pq.top().row, pq.top().col});
			pq.pop();
		}

		return res;
	}
};