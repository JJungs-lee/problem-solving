#include <iostream>

using namespace std;

int map[51][51];
int w, h;
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void DFS (int y, int x) {
	if (x < 0 || y < 0 || y >= h || x >= w) return;
	map[y][x] = 0;
	for (int i = 0; i <8; ++i) {
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];
		if(map[temp_y][temp_x])	
			DFS(temp_y, temp_x);
	}
}

void findIreland() {
	int ret = 0;

	for (int y = 0; y < h; ++y) {
		for (int x = 0; x < w; ++x) {
			if (map[y][x]) {
				DFS(y, x);
				ret++;
			}
		}
	}
	cout << ret << endl;
}

int main() {
	while(1) {
		cin >> w >> h;
		if (w == 0 && h == 0) 
			break;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x< w; ++x) {
				cin >> map[y][x];
			}
		}
		findIreland();
	}
	return 0;
}