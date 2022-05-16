class Solution {
	const int PASS_NUM = 0;
	const int FROM_IDX = 1;
	const int TO_IDX = 2;

	static const bool cmp(const vector<int> &a, const vector<int> &b) {
		return a[1] < b[1];
	}

public:
	bool carPooling(vector<vector<int>> &trips, int capacity) {
		sort(begin(trips), end(trips), cmp);

		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < trips.size(); ++i) {
			while (!pq.empty() && pq.top() <= trips[i][FROM_IDX]) {
				pq.pop();
			}

			for (int j = 0; j < trips[i][PASS_NUM]; ++j)
				pq.push(trips[i][TO_IDX]);

			if (pq.size() > capacity)
				return false;
		}

		return true;
	}
};