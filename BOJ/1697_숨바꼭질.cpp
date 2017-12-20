#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	int n, k;
	int visit[100001];
	cin >> n >> k;
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	
	
	q.push(n);
	visit[n] = 1;

	while(!q.empty()) {
		int temp = q.front();
		q.pop();

		if(temp == k) {
			cout<< visit[temp] - 1;
			break;
		}
		//-1Ä­ ÀÌµ¿
		if(temp - 1 >= 0 && visit[temp - 1] == 0) {
			q.push(temp - 1);
			visit[temp - 1] = visit[temp] + 1;
		}
		// +1Ä­ ÀÌµ¿
		if(temp + 1 <= 100000 && visit[temp + 1] ==0) {
			q.push(temp + 1);
			visit[temp + 1] = visit[temp] + 1;
		}
		// *2Ä­ ÀÌµ¿
		if(temp * 2 <= 100000 && visit[temp * 2] == 0) {
			q.push(temp * 2);
			visit[temp * 2] = visit[temp] + 1;
		}

	}
	return 0;
}