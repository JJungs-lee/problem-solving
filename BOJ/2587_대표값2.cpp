#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int nums[5];
	int sum = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> nums[i];
		sum += nums[i];
	}
	sort(nums, nums + 5);

	cout << sum / 5 << "\n";
	cout << nums[2];

	return 0;
}