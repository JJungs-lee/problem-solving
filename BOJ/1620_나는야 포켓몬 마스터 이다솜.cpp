#include <iostream>
#include <stdlib.h>
#include <string>
#include <map>

using namespace std;

int main(){

	int n; 		//포켓몬 수
	int m;		//문제의 수
	string str;
	map<string, int> board;
	string strArr[100001];

	cin >> n >> m;

	for(int i = 1; i <= n; ++i){
		cin >> strArr[i];
		board.insert(pair<string, int>(strArr[i], i));
	}

	for(int j = 0; j<m; ++j){
		char searchName[20];
		int num;

		cin >> searchName;

		num = atoi(searchName);

		if(num == 0) {
			cout << board.find(searchName)->second << endl;
		}

		else{
			cout << strArr[num] << endl;
		}

	}

	return 0;
}
