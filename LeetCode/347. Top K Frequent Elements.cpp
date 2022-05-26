class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		map<int, int> count_map;

		for (int n : nums) {
			count_map[n] += 1;
		}

		auto cmp = [&count_map](int n1, int n2) {
			return count_map[n1] > count_map[n2];
		};

		priority_queue<int, vector<int>, decltype(cmp)> heap(cmp);
		for (auto m : count_map) {
			heap.push(m.first);
			if (heap.size() > k)
				heap.pop();
		}

		vector<int> res(k);
		for (int i = k - 1; i >= 0; --i) {
			res[i] = heap.top();
			heap.pop();
		}

		return res;
	}
};