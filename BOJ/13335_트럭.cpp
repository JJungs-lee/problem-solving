#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, w, L;  // 트럭 수, 다리길이, 최대 하중
int bridge[101];

void move_truck() {
	for (int i = w - 1; i > 0; --i)
		bridge[i] = bridge[i - 1];
	bridge[0] = 0;
}

int current_bridge_weight() {
	int sum = 0;

	for (int i = 0; i < w; ++i)
		sum += bridge[i];
	return sum;
}

bool is_truck_on_the_bridge() {
	for (int i = 0; i < w; ++i) {
		if (bridge[i])
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> w >> L;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		q.push(num);
	}

	int res = 0;
	do {
		int cur_weight = current_bridge_weight();
		if (cur_weight <= L) {
			cur_weight -= bridge[w - 1];

			move_truck();

			if (!q.empty() && cur_weight + q.front() <= L) {
				bridge[0] = q.front();
				q.pop();
			}
		}
		res++;
	} while (is_truck_on_the_bridge());

	cout << res;
	return 0;
}