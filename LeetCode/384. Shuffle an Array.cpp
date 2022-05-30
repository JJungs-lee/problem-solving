class Solution {
	vector<int> origin_v;

public:
	Solution(vector<int>& nums) {
		origin_v = nums;
	}

	vector<int> reset() {
		return origin_v;
	}

	vector<int> shuffle() {
		vector<int> shuffle_v = origin_v;

		for (int i = 0; i < shuffle_v.size(); ++i) {
			int j = rand() % (shuffle_v.size());
			swap(shuffle_v[i], shuffle_v[j]);
		}
		return shuffle_v;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */