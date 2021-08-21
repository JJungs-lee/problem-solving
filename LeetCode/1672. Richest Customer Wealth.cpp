class Solution {
public:
	int maximumWealth(vector<vector<int>>& accounts) {
		int maxNum = INT_MIN;

		for (auto v : accounts) {
			int sum = 0;
			for (int x : v) {
				sum += x;
			}
			maxNum = max(maxNum, sum);
		}
		return maxNum;
	}
};