class Solution {
public:
	int minMeetingRooms(vector<vector<int>>& intervals) {
		sort(begin(intervals), end(intervals));

		priority_queue<int, vector<int>, greater<int>> pq;

		for (int i = 0; i < intervals.size(); ++i) {
			int start_time = intervals[i][0];

			if (!pq.empty() && start_time >= pq.top()) {
				pq.pop();
			}
			pq.push(intervals[i][1]);
		}
		return pq.size();
	}
};