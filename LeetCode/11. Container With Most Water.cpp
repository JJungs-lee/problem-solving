/*
 * slove #1 -> Time limited
 * time complexity - O(N^2)
 */
class Solution {
public:

	int maxArea(vector<int>& height) {
		int res = INT_MIN;

		for (int i = 0; i < height.size() - 1; i++) {
			for (int j = i + 1; j < height.size(); ++j) {
				int min_height = min(height[i], height[j]);

				res = max(res, min_height * (j - i));
			}
		}
		return res;
	}
};
/*
 * slove #2 -> Passed
 * time complexity - O(N)
 */
class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = INT_MIN;
		int l = 0;
		int r = height.size() - 1;

		while (l < r) {
			res = max(res, (r - l) * min(height[l], height[r]));

			if (height[r] > height[l])
				l++;
			else
				r--;
		}
		return res;
	}
};