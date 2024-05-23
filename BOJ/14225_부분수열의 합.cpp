#include <iostream>
using namespace std;

int n;
int arr[22];
bool find_ans[2000001];

void find_sequence(int idx, int sum) {
	if (idx == n) {
		find_ans[sum] = true;
		return;
	}

	find_sequence(idx + 1, sum + arr[idx]);
	find_sequence(idx + 1, sum);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	find_sequence(0, 0);

	int start = 1;
	while (true) {
		if (!find_ans[start]) {
			cout << start << "\n";
			return 0;
		}
		start++;
	}
	return 0;
}