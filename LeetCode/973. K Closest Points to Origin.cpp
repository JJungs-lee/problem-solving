class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<vector<int>> res;

		priority_queue<pair<int, vector<int>>> pq;

		for (vector<int>& p : points) {
			int dir = -1 * (p[0] * p[0] + p[1] * p[1]);
			pq.push({dir, p});
		}

		while (k--) {
			res.push_back(pq.top().second);
			pq.pop();
		}

		return res;
	}
};