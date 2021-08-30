#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main() {
	int f, s, g, u, d;
	bool visited[1000001] = {false};
	queue<pair<int,int>> q;

	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	q.push({s, 0});
	visited[s] = true;

	while(!q.empty()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur == g) {
			printf("%d", cnt);
			return 0;
		}

		if (cur + u <= f && !visited[cur + u]) {
			q.push({cur + u, cnt + 1});
			visited[cur + u] = true;
		}
		if (cur - d > 0 && !visited[cur - d]) {
			q.push({cur - d, cnt + 1});
			visited[cur - d] = true;
		}
	}
	printf("use the stairs");

	return 0;
}