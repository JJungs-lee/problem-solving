class NumMatrix {
	vector<vector<int>> map;

public:
	NumMatrix(vector<vector<int>>& matrix) {
		map = matrix;
	}

	void update(int row, int col, int val) {
		map[row][col] = val;
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		int sum = 0;
		for (int i = row1; i <= row2; ++i) {
			for (int j = col1; j <= col2; ++j) {
				sum += map[i][j];
			}
		}
		return sum;
	}
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */