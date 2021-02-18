#include <iostream>
using namespace std;

int n, m;
int arr[9] = { 0, };
bool visited[9] = { false, };

void backTracking(int lv) {
	if (lv == m) {
		for (int i = 0; i < m; ++i) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			arr[lv] = i;
			backTracking(lv + 1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	backTracking(0);

	return 0;
}