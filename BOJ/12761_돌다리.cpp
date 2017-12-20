// 병신임.... 문제 입력조건을 잘못봐서
// n, m, a, b 순으로 받아서 계속 틀림... 
// 문제를 잘읽자!! 진짜 ... 
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int main() {
	// n 동규, m 주미
	int n, m;
	int a, b;
	int visit[100001]; 
	cin >> a >> b >> n >> m;

	memset(visit, 0, sizeof(visit));
	queue<int> q;

	q.push(n);
	visit[n] = 1;
	while(!q.empty()) {
		int num = q.front();
		q.pop(); 

		if(num == m) {
			cout << visit[num] -1 << endl;
			break;
		} 
		//-1한칸
		if(num - 1 >= 0 && visit[num - 1] == 0) {
			q.push(num - 1);
			visit[num - 1] = visit[num] + 1;
		}
		//+1 한칸
		if(num + 1 <= 100000 && visit[num + 1] == 0) {
			q.push(num + 1);
			visit[num + 1] = visit[num] + 1;
		}
		//+A만큼
		if(num + a <= 100000 && visit[num + a] == 0) {
			q.push(num + a);
			visit[num + a] = visit[num] + 1;
		}
		//+B만큼
		if(num + b <= 100000 && visit[num + b] == 0) {
			q.push(num + b);
			visit[num + b] = visit[num] + 1;
		}
		//-A만큼
		if(num - a >= 0 && visit[num - a] == 0) {
			q.push(num - a);
			visit[num - a] = visit[num] + 1;
		}
		//-B만큼
		if(num - b >= 0 && visit[num - b] == 0) {
			q.push(num - b);
			visit[num - b] = visit[num] + 1;
		}
		//A배만큼
		if(num * a <= 100000 && visit[num * a] == 0) {
			q.push(num * a);
			visit[num * a] = visit[num] + 1;
		}
		//B배만큼
		if(num * b <= 100000 && visit[num * b] == 0) {
			q.push(num * b);
			visit[num * b] = visit[num] + 1;
		}

		////-A배만큼
		//if(num * -1 * a >= 0 && visit[num * -1 * a] == 0) {
		//	q.push(num * -1 * a);
		//	visit[num * -1 * a] = visit[num] + 1;
		//}
		////-B배만큼
		//if(num * -1 * b >= 0 && visit[num * -1 * b] == 0) {
		//	q.push(num * -1 * b);
		//	visit[num * -1 * b] = visit[num] + 1;
		//}
	}
	return 0;
}