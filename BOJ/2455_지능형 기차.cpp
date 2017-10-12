#include <iostream>
#include <algorithm>

using namespace std;

int arr[4][2];

int main(){

	int num = 0;
	int ret = -1;
	for(int i = 0; i<4; ++i){
		for(int j = 0; j<2; ++j){
			cin >> arr[i][j];
		}
	}
	for(int i = 0; i<4; ++i){
		num -= arr[i][0];
		num += arr[i][1];

		ret = max(ret, num);
	}
	cout << ret << endl;
	return 0;
}