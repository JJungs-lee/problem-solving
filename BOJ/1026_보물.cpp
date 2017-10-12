#include <iostream>
#include <algorithm>

using namespace std;

bool isUp(int a, int b) { return a>b; };
int main(){

	int A[51];
	int B[51];
	int n;
	int sum = 0;
	cin >> n;

	for(int i = 0; i<2; ++i){
		for(int j = 0; j<n; ++j){
			if(i == 0) cin >> A[j];
			else cin >> B[j];
		}
	}

	sort(A, A + n);
	sort(B, B + n, isUp);

	for(int i = 0; i<n; ++i){
		sum += A[i] * B[i];
	}
	cout << sum;
	return 0;
}