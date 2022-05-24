class Solution {
public:
	int maximumCandies(vector<int>& candies, long long k) {
		int left = 0, right = 10e7;

		while (left < right) {
			long sum = 0;
			long mid = (left + right + 1) / 2;
			for (int n : candies) {
				sum += n / mid;
			}
			if (k > sum)
				right = mid - 1;
			else
				left = mid;
		}
		return left;
	}
};