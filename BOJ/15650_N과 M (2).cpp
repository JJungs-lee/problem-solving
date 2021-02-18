#include <iostream>
#include <vector>
using namespace std;

int n, m;
bool visited[9] = {false,};
vector<int> v;

void backTracking(int lv, int num) {
	if (lv == m) {
		for (int iter:v) {
			cout << iter << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; ++i) {
		if (!visited[i] && i > num) {
			visited[i] = true;
			v.push_back(i);
			backTracking(lv + 1, i);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	backTracking(0, 0);

	return 0;
}