class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& arr) {
		int n = arr.size();

		if (n == 2)
			return true;

		sort(arr.begin(), arr.end());

		int diff = abs(arr[0] - arr[1]);

		for (int i = 1; i < n - 1; ++i) {
			if (diff != abs(arr[i] - arr[i + 1]))
				return false;
		}
		return true;
	}
};