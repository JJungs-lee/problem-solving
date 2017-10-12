#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n;		//정점의 개수
int board[1001][1001];			//어느쪽으로 갈수있는지 저장
bool isVisit[1001];				//방문했는지 저장
queue<int> q;					//bfs시 사용

void DFS(int start);
void BFS(int start);

int main(){

	int m;		//간선의 개수
	int v;		//시작할 지점

	memset(board, -1, sizeof(board));
	memset(isVisit, false, sizeof(isVisit));

	cin >> n >> m >> v;

	while(m--){
		int s;		//시작
		int e;		//끝

		cin >> s >> e;
		board[s][e] = board[e][s] = 1;
	}
	DFS(v);
	memset(isVisit, false, sizeof(isVisit));
	cout << endl;

	BFS(v);

	return 0;
}

void DFS(int start){

	isVisit[start] = true;
	cout << start << ' ';
	for(int i = 1; i <= n; ++i){
		if(board[start][i] == 1 && !isVisit[i]){
			DFS(i);
		}
	}
}

void BFS(int start){

	isVisit[start] = true;

	q.push(start);

	while(!q.empty()){
		start = q.front();
		q.pop();

		cout << start << ' ';
		//갈수있는곳을 넣음

		for(int i = 1; i <= n; ++i){
			if(board[start][i] == 1 && !isVisit[i]) {
				q.push(i);
				isVisit[i] = true;
			}
		}
	}
}