#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct point{
	int x;
	int y;
	int cnt;
};
int main(){
	//N = Y , M = X
	int N, M;
	cin >> N >> M;
	int map[102][102];
	string str;
	for(int i = 0; i < N; ++i){
		cin >> str;
		for(int j = 0; j < M; ++j){
			map[i][j] = str[j] - '0';
		}
	}
	point startPoint;
	startPoint.x = 0;
	startPoint.y = 0;
	startPoint.cnt = 1;
	map[0][0] = 0;

	queue<point> q;
	q.push(startPoint);

	while(!q.empty()){
		point p = q.front();
		q.pop();

		if(p.x == N - 1 && p.y == M - 1){
			cout << p.cnt;
			break;
		}
		point inserPoint;
		//왼쪽
		if(p.x - 1 >= 0 && map[p.x - 1][p.y] != 0){
			inserPoint.x = p.x - 1;
			inserPoint.y = p.y;
			inserPoint.cnt = p.cnt + 1;
			q.push(inserPoint);
			map[p.x - 1][p.y] = 0;
		}
		//오른쪽
		if(p.x + 1 < N && map[p.x + 1][p.y] != 0){
			inserPoint.x = p.x + 1;
			inserPoint.y = p.y;
			inserPoint.cnt = p.cnt + 1;
			q.push(inserPoint);
			map[p.x + 1][p.y] = 0;
		}
		//위
		if(p.y - 1 >= 0 && map[p.x][p.y - 1] != 0){
			inserPoint.x = p.x;
			inserPoint.y = p.y - 1;
			inserPoint.cnt = p.cnt + 1;
			q.push(inserPoint);
			map[p.x][p.y - 1] = 0;
		}
		//아래
		if(p.y + 1 < M && map[p.x][p.y + 1] != 0){
			inserPoint.x = p.x;
			inserPoint.y = p.y + 1;
			inserPoint.cnt = p.cnt + 1;
			q.push(inserPoint);
			map[p.x][p.y + 1] = 0;
		}
	}
	return 0;
}