#include <iostream>

using namespace std;

int main(){
	int n, m;
	int arr[300][300];
	int testCase;

	//input
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> arr[i][j];
		}
	}
	//slove
	cin >> testCase;
	while(testCase--){
		int sum = 0;
		int x0, y0;
		int x1, y1;

		cin >> x0 >> y0 >> x1 >> y1;

		for(int i = x0 - 1; i < x1; ++i){
			for(int j = y0 - 1; j < y1; ++j){
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}
	return 0;
}