#include <iostream>
using namespace std;

#define MAX_MAP 6561
char map[MAX_MAP][MAX_MAP];

void star(int y, int x, int size){
	
	if(size == 1) {
		map[y][x] = '*';
		return;
	}
	
	int div = size/3;
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			if(i == 1 && j == 1) 
				continue;
			else
				star(y+(i*div),x+(j*div),div);
		}
	}	
}

int main() {
	// your code goes here
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			map[i][j] =' ';
		}
	}
	star(0, 0, n);
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}