class Solution {
	struct cmp {
		int operator()(pair<int, string> &a, pair<int, string> &b) {
			if (a.first == b.first)
				return a.second > b.second;

			return a.first < b.first;
		}
	};

public:
	vector<string> topKFrequent(vector<string> &words, int k) {
		map<string, int> count_map;
		vector<string> res;

		for (string word : words)
			count_map[word] += 1;

		priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

		for (auto p : count_map) {
			pq.push({p.second, p.first});
		}
		while (k--) {
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}
};