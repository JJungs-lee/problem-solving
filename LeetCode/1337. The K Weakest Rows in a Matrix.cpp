class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int m = mat.size();
		int n = mat[0].size();

		vector<int> count_sol(m, 0);

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (mat[i][j])
					count_sol[i]++;
				else
					break;
			}
		}

		auto cmp = [](pair<int, int> a, pair<int, int> b) {
			if (a.second == b.second)
				return a.first > b.first;
			return a.second > b.second;
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

		for (int i = 0; i < count_sol.size(); ++i) {
			pq.push({i, count_sol[i]});
		}
		vector<int> res;

		while (k--) {
			res.push_back(pq.top().first);
			pq.pop();
		}
		return res;
	}
};