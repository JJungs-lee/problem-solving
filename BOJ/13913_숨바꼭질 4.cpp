#include <deque>
#include <iostream>
#include <queue>
using namespace std;

#define MX 100001
int start, finish;
int visited[100002];
int board[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> start >> finish;
	queue<int> q;
	q.push(start);
	board[start] = 1;
	visited[start] = start;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur * 2 < MX && !board[cur * 2]) {
			visited[cur * 2] = cur;
			board[cur * 2] = board[cur] + 1;
			q.push(cur * 2);
			if (cur * 2 == finish) {
				break;
			}
		}
		if (cur + 1 < MX && !board[cur + 1]) {
			visited[cur + 1] = cur;
			board[cur + 1] = board[cur] + 1;
			q.push(cur + 1);
			if (cur + 1 == finish) {
				break;
			}
		}
		if (cur - 1 >= 0 && !board[cur - 1]) {
			visited[cur - 1] = cur;
			board[cur - 1] = board[cur] + 1;
			q.push(cur - 1);
			if (cur - 1 == finish) {
				break;
			}
		}
	}

	cout << board[finish] - 1 << "\n";
	deque<int> track = {finish};
	while (track.front() != start)
		track.push_front(visited[track.front()]);
	for (int p : track)
		cout << p << ' ';

	return 0;
}