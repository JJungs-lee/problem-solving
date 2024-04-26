#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[100001];
int state[100001];
vector<int> res;
#define NOT_VISITED 0
#define VISITED -1

void run(int x) {
	int cur = x;

	while (true) {
		state[cur] = x;
		cur = arr[cur];

		if (state[cur] == x) {
			while (state[cur] != VISITED) {
				state[cur] = VISITED;
				res.push_back(cur);
				cur = arr[cur];
			}
			return;
		} else if (state[cur] != 0) {
			return;
		}
	}
}

int main() {
	int n;
	cin >> n;

	fill(state + 1, state + n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; ++i) {
		if (state[i] == NOT_VISITED) {
			run(i);
		}
	}
	sort(res.begin(), res.end());
	cout << res.size() << "\n";
	for (int num : res) {
		cout << num << "\n";
	}

	return 0;
}