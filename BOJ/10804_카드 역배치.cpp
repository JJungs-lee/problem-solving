#include <algorithm>
#include <iostream>
using namespace std;

int nums[21];

void reverse(int a, int b) {
	for (int i = 0; i < (b - a + 1) / 2; ++i)
		swap(nums[a + i], nums[b - i]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 20; ++i) {
		nums[i] = i;
	}

	for (int i = 1; i <= 10; ++i) {
		int a, b;
		cin >> a >> b;
		reverse(a, b);
	}

	for (int i = 1; i <= 20; ++i) {
		cout << nums[i] << ' ';
	}

	return 0;
}