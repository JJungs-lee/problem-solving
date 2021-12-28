#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	int arr[11];
	cin >> n >> k;
	
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int ret = 0;
	int idx = n - 1;
	while (k != 0) {
		if (k < arr[idx])
			idx--;
		int div = k / arr[idx];
		ret += div;
		k -= arr[idx] * div;
	}
	cout << ret;
	return 0;
}
