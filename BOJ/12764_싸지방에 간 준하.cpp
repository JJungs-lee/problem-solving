#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> remain_seat;
int checked[100001] = {
    0,
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int start, end;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> start >> end;
		v.push_back({start, end});
	}
	sort(v.begin(), v.end());

	int seat = 0;
	for (int i = 0; i < n; ++i) {
		while (!pq.empty()) {
			auto [end_time, idx] = pq.top();

			if (end_time <= v[i].first) {
				remain_seat.push(idx);
				pq.pop();
			} else {
				break;
			}
		}

		if (remain_seat.empty()) {
			checked[seat]++;
			pq.push({v[i].second, seat++});
		} else {
			int idx = remain_seat.top();
			remain_seat.pop();

			pq.push({v[i].second, idx});
			checked[idx]++;
		}
	}
	cout << seat << endl;
	for (int i = 0; i < seat; ++i)
		cout << checked[i] << ' ';

	return 0;
}
