class SubrectangleQueries {
	vector<vector<int>> v;

public:
	SubrectangleQueries(vector<vector<int>>& rectangle) {
		v = rectangle;
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
		for (int y = row1; y <= row2; ++y) {
			for (int x = col1; x <= col2; ++x) {
				v[y][x] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return v[row][col];
	}
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */