#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n;		//������ ����
int board[1001][1001];			//��������� �����ִ��� ����
bool isVisit[1001];				//�湮�ߴ��� ����
queue<int> q;					//bfs�� ���

void DFS(int start);
void BFS(int start);

int main(){

	int m;		//������ ����
	int v;		//������ ����

	memset(board, -1, sizeof(board));
	memset(isVisit, false, sizeof(isVisit));

	cin >> n >> m >> v;

	while(m--){
		int s;		//����
		int e;		//��

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
		//�����ִ°��� ����

		for(int i = 1; i <= n; ++i){
			if(board[start][i] == 1 && !isVisit[i]) {
				q.push(i);
				isVisit[i] = true;
			}
		}
	}
}