class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start = 0;
		int end = nums.size() - 1;
		int mid;

		while (true) {
			mid = (start + end) / 2;
			if (start > end)
				return -1;

			if (nums[mid] == target)
				return mid;

			if (nums[mid] < target)
				start = mid + 1;
			else
				end = mid - 1;
		}
		return 0;
	}
};