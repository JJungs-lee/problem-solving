class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();

		int start = 0;
		int end = m * n - 1;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (target == matrix[mid / n][mid % n])
				return true;

			if (target > matrix[mid / n][mid % n])
				start = mid + 1;
			else
				end = mid - 1;
		}
		return false;
	}
};