#include <iostream>
#include <cmath>

using namespace std;

bool findSosu(int num){
	int squ;
	squ = (int)sqrt((double)(num));

	if(num == 2) return true;
	if(num % 2 == 0 || num == 1) return false;

	for(int i = 3; i <= squ; ++i){
		if(num%i == 0) return false;
	}

	return true;
}

int main(){
	int n;
	int cnt = 0;
	int arr[101];

	cin >> n;
	for(int i = 0; i<n; ++i){
		cin >> arr[i];
		if(findSosu(arr[i])) cnt++;
	}
	cout << cnt;
	return 0;
}