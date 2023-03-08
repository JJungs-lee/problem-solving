#include <algorithm>
#include <iostream>

using namespace std;

int n;
int arr[1001];
int cache[1001];

int slove(int start) {
	int& ret = cache[start];

	if (ret != -1) return ret;

	ret = 1;

	for (int next = start + 1; next <= n; ++next) {
		if (arr[start] < arr[next]) {
			ret = max(ret, slove(next) + 1);
		}
	}
	return ret;
}

int main() {
	int cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		cache[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		cnt = max(cnt, slove(i));
	}
	cout << cnt;
	return 0;
}