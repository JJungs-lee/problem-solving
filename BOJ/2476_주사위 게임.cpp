#include <iostream>
#include <algorithm>

using namespace std;

int main(){

	int n;		//사람수
	int arr[1000][3];
	int cash = 0;

	//input
	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 3; ++j) cin >> arr[i][j];
	}

	//slove
	for(int i = 0; i < n; ++i){

		//3개다 같을때
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]){
			cash = max(cash, 10000 + (arr[i][0] * 1000));
		}
		//2개가 같을떄
		else if((arr[i][0] == arr[i][1])){
			cash = max(cash, 1000 + (arr[i][0] * 100));
		} else if((arr[i][0] == arr[i][2])){
			cash = max(cash, 1000 + (arr[i][0] * 100));
		} else if((arr[i][1] == arr[i][2])){
			cash = max(cash, 1000 + (arr[i][1] * 100));
		}
		//1개 일경우
		else{
			int maxN = 0;
			maxN = max(arr[i][0], arr[i][1]);
			maxN = max(maxN, arr[i][2]);
			cash = max(cash, maxN * 100);
		}

	}
	cout << cash << endl;

	return 0;
}