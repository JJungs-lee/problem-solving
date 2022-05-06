class Solution {
public:
	bool binary_search(int find_num, vector<int>& arr, int d) {
		int start = 0;
		int end = arr.size() - 1;

		while (start <= end) {
			int mid = (start + end) / 2;
			int distance = arr[mid] - find_num;

			if (abs(distance) <= d) {
				return false;
			}

			if (distance > 0) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		return true;
	}

	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int res = 0;
		sort(begin(arr2), end(arr2));

		for (int& find_num : arr1) {
			if (binary_search(find_num, arr2, d)) {
				res++;
			}
		}
		return res;
	}

	// other solution using upper_bound, lower_bound
	// sort(begin(B), end(B));
	// int ans = 0;
	// for (int n : A) {
	//     if (upper_bound(begin(B), end(B), n + d) == lower_bound(begin(B), end(B), n - d)) ++ans;
	// }
};