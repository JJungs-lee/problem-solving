class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq;

		for (int n : stones)
			pq.push(n);

		while (pq.size() > 1) {
			int first = pq.top();
			pq.pop();
			int second = pq.top();
			pq.pop();
			pq.push(abs(first - second));
		}
		return pq.top();
	}
};