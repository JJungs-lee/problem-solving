#include <vector>
long long sum(std::vector<int>& a) {
	long long ans = 0;
	for (long long num : a) {
		ans += num;
	}
	return ans;
}
