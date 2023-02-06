class Solution {
	int dy[4] = {0, 0, -1, 1};
	int dx[4] = {1, -1, 0, 0};

public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
		int m = image.size();
		int n = image[0].size();
		int origin_color = image[sr][sc];
		if (origin_color == newColor)
			return image;

		queue<pair<int, int>> q;
		q.push({sr, sc});
		image[sr][sc] = newColor;

		while (!q.empty()) {
			auto [cur_y, cur_x] = q.front();
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int ny = cur_y + dy[i];
				int nx = cur_x + dx[i];

				if (ny < 0 || nx < 0 || ny >= m || nx >= n)
					continue;

				if (image[ny][nx] == origin_color) {
					q.push({ny, nx});
					image[ny][nx] = newColor;
				}
			}
		}
		return image;
	}
};
