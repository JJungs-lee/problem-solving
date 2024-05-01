#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
vector<int> v;

void backtracking(int count) {
	if (count == m) {
		for (auto num : v) {
			cout << num << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		v.push_back(arr[i]);
		backtracking(count + 1);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	backtracking(0);

	return 0;
}