class Solution {
public:
	vector<int> decode(vector<int>& encoded, int first) {
		vector<int> v(1, first);

		for (int x : encoded) {
			v.push_back(v.back() ^ x);
		}
		return v;
	}
};