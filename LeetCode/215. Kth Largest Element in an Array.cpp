class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;

		for (int n : nums) {
			if (pq.size() < k) {
				pq.push(n);
				continue;
			}
			if (pq.top() < n) {
				pq.pop();
				pq.push(n);
			}
		}

		return pq.top();
	}
};