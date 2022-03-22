// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		if (n == 1)
			return 1;

		unsigned long start = 0;
		unsigned long end = n;
		unsigned long mid;
		while (true) {
			mid = (start + end) / 2;
			bool prevVersion = isBadVersion(mid);
			bool nextVersion = isBadVersion(mid + 1);

			if (prevVersion != nextVersion)
				return mid + 1;

			if (prevVersion == false) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
	}
};