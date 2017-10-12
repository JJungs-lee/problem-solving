#include <iostream>

using namespace std;

int main(){
	int N, S;
	int arr[21];
	int sum = 0;
	int ret = 0;
	//input
	cin >> N >> S;
	for(int i = 0; i < N; ++i){
		cin >> arr[i];
	}

	//solve
	for(int i = 1; i < (1 << N); ++i){
		for(int j = 0; j < N; ++j){
			if(i & (1 << j)){
				sum += arr[j];
			}
		}
		if(sum == S) ret++;
		sum = 0;
	}
	cout << ret << endl;
	return 0;
}