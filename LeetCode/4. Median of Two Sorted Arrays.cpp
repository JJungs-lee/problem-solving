class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> v(nums1.size() + nums2.size());
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());

		int size = v.size();
		return size & 1 ? v[size / 2] : (v[(size / 2) - 1] + v[size / 2]) / 2.0;
	}
};