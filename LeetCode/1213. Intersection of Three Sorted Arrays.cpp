class Solution {
	int bSearch(vector<int>& arr, int target) {
		int start = 0;
		int end = arr.size() - 1;

		while (start <= end) {
			int mid = (start + end) / 2;

			if (arr[mid] == target)
				return arr[mid];

			if (arr[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return -1;
	}

public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int> res;

		for (int t : arr1) {
			int find_idx_arr2 = bSearch(arr2, t);
			int find_idx_arr3 = bSearch(arr3, t);

			if (find_idx_arr2 == -1 || find_idx_arr3 == -1)
				continue;
			res.push_back(t);
		}
		return res;
	}
};