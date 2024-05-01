#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
vector<int> v;

void backtracking(int count, int num) {
	if (count == m) {
		for (auto iter : v) {
			cout << iter << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; ++i) {
		if (arr[i] >= num) {
			v.push_back(arr[i]);
			backtracking(count + 1, arr[i]);
			v.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);

	backtracking(0, 0);

	return 0;
}