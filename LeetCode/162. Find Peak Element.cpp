class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		return search(nums, 0, nums.size() - 1);
	}

	int search(vector<int>& nums, int l, int r) {
		if (l == r)
			return l;

		int mid = (l + r) / 2;
		if (nums[mid] > nums[mid + 1])
			return search(nums, l, mid);
		return search(nums, mid + 1, r);
	}
};
