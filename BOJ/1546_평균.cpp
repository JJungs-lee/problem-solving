#include <iostream>

using namespace std;

int main(){
	//최대값 M
	//모든 점수를  점수/M*100으로 변경
	//과목의 개수
	
	int n;
	double m = 0;
	double arr[1001];
	double ret = 0;
	cin >> n;
	//점수 입력받음
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		if(arr[i] > m){
			m = arr[i];
		}
	}

	//점수 변경
	for(int i = 0; i < n; ++i){
		ret += arr[i] / m * 100;
	}
	cout << fixed;
	cout.precision(2);
	cout << ret / n << endl;

	return 0;
}