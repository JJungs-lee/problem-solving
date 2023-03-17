class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() && nums[i] <= 0; ++i) {
			if (i != 0 && nums[i - 1] == nums[i])
				continue;
			int left = i + 1;
			int right = nums.size() - 1;

			int sum = 0;
			while (left < right) {
				sum = nums[i] + nums[left] + nums[right];

				if (sum > 0) {
					right--;
				} else if (sum < 0) {
					left++;
				} else {
					res.push_back({nums[i], nums[left++], nums[right--]});
					while (left < right && nums[left] == nums[left - 1])
						++left;
				}
			}
		}
		return res;
	}
};