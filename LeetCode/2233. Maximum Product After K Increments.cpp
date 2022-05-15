class Solution {
public:
	int maximumProduct(vector<int>& nums, int k) {
		if (nums.size() == 1)
			return nums[0] + k;

		priority_queue<int> pq;
		long long res = 1;

		for (int n : nums) {
			pq.push(-1 * n);
		}

		while (k--) {
			int cur = pq.top();
			pq.pop();
			pq.push(cur - 1);
		}

		while (!pq.empty()) {
			res *= (-1 * pq.top());
			res %= 1000000007;
			pq.pop();
		}

		return res;
	}
};