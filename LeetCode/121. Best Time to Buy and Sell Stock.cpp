class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int max_price = 0;
		int low_price = INT_MAX;

		for (int p : prices) {
			if (low_price > p)
				low_price = p;
			else if (p - low_price > max_price)
				max_price = p - low_price;
		}
		return max_price;
	}
};