#include <iostream>
#include <memory.h>

using namespace std;

int board[51][51];
int m, n;		//m == x , n == y

void DFS(int y, int x){
	//	if (x<0 || x>m + 1 || y<0 || y>n + 1) return;

	if(x + 1 <m && board[y][x + 1]){
		board[y][x + 1] = 0;
		DFS(y, x + 1);
	}
	if(x - 1 > -1 && board[y][x - 1]){
		board[y][x - 1] = 0;
		DFS(y, x - 1);
	}
	if(y + 1 <n && board[y + 1][x]){
		board[y + 1][x] = 0;
		DFS(y + 1, x);
	}
	if(y - 1 >-1 && board[y - 1][x]){
		board[y - 1][x] = 0;
		DFS(y - 1, x);
	}
}

int main(){
	int testCase;
	cin >> testCase;

	while(testCase--){
		int numOfPoint;
		int x, y;

		//init
		memset(board, 0, sizeof(board));

		//input
		cin >> m >> n >> numOfPoint;
		while(numOfPoint--){
			cin >> x >> y;
			board[y][x] = 1;
		}
		//slove
		int ret = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(board[i][j] == 1) {
					DFS(i, j);
					ret++;
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}