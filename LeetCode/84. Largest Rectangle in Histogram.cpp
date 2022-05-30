class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		stack<int> s;
		int n = heights.size();
		int res = 0;

		for (int i = 0; i < n; ++i) {
			while (!s.empty() && heights[s.top()] >= heights[i]) {
				int h = heights[s.top()];
				s.pop();
				int l = s.empty() ? -1 : s.top();

				res = max(res, (i - l - 1) * h);
			}
			s.push(i);
		}
		while (!s.empty()) {
			int h = heights[s.top()];
			s.pop();
			int l = s.empty() ? -1 : s.top();

			res = max(res, (n - l - 1) * h);
		}
		return res;
	}
};