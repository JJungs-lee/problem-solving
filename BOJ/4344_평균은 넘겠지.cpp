#include <iostream>

using namespace std;

int main(){
	int testCase;
	cin >> testCase;

	while(testCase--){
		int n;
		double arr[1001];
		double sum = 0;
		double aver = 0;
		int ret = 0;
		cin >> n;

		for(int i = 0; i < n; ++i){
			cin >> arr[i];
			sum += arr[i];
		}
		aver = sum / n;
		for(int i = 0; i < n; ++i){
			if(arr[i] > aver){
				ret++;
			}
		}

		cout << fixed;
		cout.precision(3);

		cout << (ret * 100.000 / n) << "%" << endl;
	}
	return 0;
}