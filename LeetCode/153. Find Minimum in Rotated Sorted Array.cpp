// [2,3,4,5,6,0,1]
//        ^     ^
// [6,0,1,2,3,4,5]  answer must be in left part
//        ^  <  ^
// [0,1,2,3,4,5,6]  answer must be in left part
//        ^  <  ^
// [1,2,3,4,5,6,0]
//        ^     ^
class Solution {
public:
	int findMin(vector<int>& nums) {
		int l = 0;
		int r = nums.size() - 1;

		while (l < r) {
			int mid = l + (r - l) / 2;
			if (nums[mid] < nums[r])
				r = mid;
			else
				l = mid + 1;
		}

		return nums[l];
	}
};