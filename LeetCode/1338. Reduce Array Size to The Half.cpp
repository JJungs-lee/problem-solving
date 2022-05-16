// first version using lamda express
class Solution {
public:
	int minSetSize(vector<int>& arr) {
		map<int, int> count_map;

		for (int n : arr)
			count_map[n] += 1;

		auto cmp = [&count_map](int a, int b) { return count_map[a] < count_map[b]; };
		priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

		for (pair<int, int> p : count_map)
			pq.push(p.first);

		int size = arr.size();
		int res = 0;
		int sum = 0;
		while (!pq.empty()) {
			sum += count_map[pq.top()];
			res++;
			pq.pop();
			if (size / 2 >= size - sum) {
				return res;
			}
		}

		return res;
	}
};

// second version
class Solution {
public:
	int minSetSize(vector<int>& arr) {
		map<int, int> count_map;

		for (int n : arr)
			count_map[n] += 1;

		priority_queue<pair<int, int>> pq;

		for (pair<int, int> p : count_map)
			pq.push({p.second, p.first});

		int size = arr.size();
		int res = 0;
		int sum = 0;
		while (!pq.empty()) {
			sum += pq.top().first;
			res++;
			pq.pop();
			if (size / 2 >= size - sum) {
				return res;
			}
		}

		return res;
	}
};