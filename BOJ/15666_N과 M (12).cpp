#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[10];
bool visited[10];
vector<int> v;

void backtracking(int count) {
	if (count == m) {
		if (is_sorted(v.begin(), v.begin() + m)) {
			for (auto iter : v) {
				cout << iter << " ";
			}
			cout << '\n';
		}
		return;
	}

	int tmp = 0;
	for (int i = 0; i < n; ++i) {
		if (tmp != arr[i]) {
			v.push_back(arr[i]);
			tmp = arr[i];
			backtracking(count + 1);
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

	backtracking(0);

	return 0;
}