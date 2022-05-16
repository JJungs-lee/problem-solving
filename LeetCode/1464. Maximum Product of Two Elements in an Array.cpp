class Solution {
public:
	int maxProduct(vector<int>& nums) {
		priority_queue<int> pq;

		for (int n : nums)
			pq.push(n);

		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();

		return (num1 - 1) * (num2 - 1);
	}
};