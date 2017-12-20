#include <iostream>
#include <stack>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 0 오른쪽, 1 왼쪽, 2 아래쪽, 3 위쪽
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main() {
	int n;
	int board[26][26];

	memset(board, -1, sizeof(board));
	cin >> n;
	for(int y = 0; y < n; ++y) {
		string str;
		cin >> str;
		for(int x = 0; x < n; ++x) {
			board[y][x] = str[x] - '0';
		}
	}
	stack< pair<int, int> > s;
	vector<int> v;
	
	for(int y = 0; y < n; ++y) {
		for(int x = 0; x < n; ++x) {
			int cnt = 0;
			bool flag = false;
			if(board[y][x] == 1) {
				s.push(make_pair(x, y));
				board[y][x] = 0;
				cnt++;
				while(!s.empty()) {
					flag = false;
					for(int i = 0; i < 4; ++i) {
						int moveX = s.top().first + dx[i];
						int moveY = s.top().second + dy[i];

						if(moveX < 0 || moveX > n || moveY < 0 || moveY > n) {
							continue;
						}
						if(board[moveY][moveX] == 1) {
							board[moveY][moveX] = 0;
							cnt++;
							flag = true;
							s.push(make_pair(moveX, moveY));
							break;
						}
					}
					if(!flag) {
						s.pop();
					}
				}
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i] << endl;
	}
	return 0;
}