class Solution {
public:
	int peakIndexInMountainArray(vector<int>& arr) {
		int start = 0;
		int end = arr.size() - 1;
		int mid = (start + end) / 2;

		while (mid != 0 && mid != arr.size() - 1) {
			bool is_incread = arr[mid - 1] < arr[mid];
			bool is_decread = arr[mid] > arr[mid + 1];

			if (is_incread && is_decread)
				return mid;

			if (is_incread && !is_decread) {
				start = mid + 1;
			} else if (!is_incread && is_decread) {
				end = mid;
			}
			mid = (start + end) / 2;
		}
		return mid;
	}
};