#include <stdio.h>
#define CITY 1001
#define INF 987654321

int n;	//도시의 개수
int m;	//버스의 개수
int g[CITY][CITY];
int visited[CITY];
long long dist[CITY];

void dijkstra(int start, int end) {
	
	dist[start] = 0;

	for (int i = 1; i <= n; ++i) {
		int minNum = INF;
		int idx = 0;
		// 최소점을 찾음
		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dist[j] < minNum) {
				minNum = dist[j];
				idx = j;
			}
		}
		visited[idx] = true;

		for (int j = 1; j <= n; ++j) {
			if (!visited[j] && dist[j] > dist[idx] + g[idx][j]) {
				dist[j] = dist[idx] + g[idx][j];
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);

	for (int i = 1; i <= n; ++i) {
		visited[i] = 0;
		dist[i] = INF;
		for (int j = 1; j <= n; ++j) {
			g[i][j] = INF;
		}
	}

	int start, end, weight;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &start, &end, &weight);
		if (g[start][end] > weight) {
			g[start][end] = weight;
		}
	}
	scanf("%d %d", &start, &end);
	dijkstra(start, end);

	printf("%d\n", dist[end]);
	return 0;
}
