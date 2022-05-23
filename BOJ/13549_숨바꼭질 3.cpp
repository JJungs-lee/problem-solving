#include <cstring>
#include <deque>
#include <iostream>

using namespace std;
#define MAX_AREA 200000

deque<pair<int, int>> q;
int visited[MAX_AREA + 1];

void bfs(int n, int k) {
	while (!q.empty()) {
		auto [cur, time] = q.front();
		q.pop_front();
		if (cur == k) {
			cout << time << endl;
			break;
		}

		if (cur * 2 <= MAX_AREA && !visited[cur * 2]) {
			visited[cur * 2] = visited[cur] + 1;
			q.push_front({cur * 2, time});
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			visited[cur - 1] = visited[cur] + 1;
			q.push_back({cur - 1, time + 1});
		}
		if (cur + 1 <= MAX_AREA && !visited[cur + 1]) {
			visited[cur + 1] = visited[cur] + 1;
			q.push_back({cur + 1, time + 1});
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;
	memset(visited, 0, sizeof(visited));
	q.push_back({n, 0});
	visited[n] = 1;

	bfs(n, k);

	return 0;
}
