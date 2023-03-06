class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int idx = 0;
		int i = 0;
		while (true) {
			i++;
			if (idx < arr.size() && i == arr[idx]) {
				idx++;
			} else {
				k--;
				if (!k)
					break;
			}
		}
		return i;
	}
};