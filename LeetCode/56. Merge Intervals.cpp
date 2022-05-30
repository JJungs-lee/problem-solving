class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		if (intervals.empty())
			return {};

		vector<vector<int>> res;
		sort(intervals.begin(), intervals.end());

		int start_idx = 0;

		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++) {
			if (res.back()[1] < intervals[i][0])
				res.push_back(intervals[i]);
			else
				res.back()[1] = max(res.back()[1], intervals[i][1]);
		}

		return res;
	}
};