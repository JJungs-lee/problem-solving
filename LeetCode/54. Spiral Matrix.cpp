class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();

		vector<int> res;
		int up = 0;
		int left = 0;
		int down = m - 1;
		int right = n - 1;
		while (res.size() < m * n) {
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[up][i]);

			for (int i = up + 1; i <= down; ++i)
				res.push_back(matrix[i][right]);

			if (up != down) {
				for (int i = right - 1; i >= left; --i)
					res.push_back(matrix[down][i]);
			}
			if (left != right) {
				for (int i = down - 1; i > up; --i)
					res.push_back(matrix[i][left]);
			}
			left++;
			right--;
			up++;
			down--;
		}
		return res;
	}
};