#include <cstring>
#include <queue>
#include <iostream>
#include <climits>

using namespace std;
#define MAX_AREA 100000

queue<pair<int, int>> q;
int visited[MAX_AREA + 1];
int res = 0;
int res_time = INT_MAX;

void bfs(int n, int k) {
	while (!q.empty()) {
		auto [cur, time] = q.front();
		q.pop();

		visited[cur] = true;
		if (cur == k) {
			res_time = min(res_time, time);
			if (res_time != INT_MAX && res_time == time)
				res++;
			continue;
		}

		if (cur * 2 <= MAX_AREA && !visited[cur * 2]) {
			q.push({cur * 2, time + 1});
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({cur - 1, time + 1});
		}
		if (cur + 1 <= MAX_AREA && !visited[cur + 1]) {
			q.push({cur + 1, time + 1});
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;
	memset(visited, 0, sizeof(visited));
	q.push({n, 0});

	bfs(n, k);
	cout << res_time << "\n" << res << endl;

	return 0;
}
