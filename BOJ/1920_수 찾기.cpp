#include <iostream>
#include <algorithm>

using namespace std;
int cnt;
int arr[100001];

int findAnswer(int findNum){

	int start = 0;
	int end = cnt - 1;
	int mid = (start + end) / 2;

	for(int j = 0; j < 5000; ++j){
		if(arr[mid] == findNum) return true;
		if(arr[mid] < findNum) start = mid + 1;
		else end = mid - 1;

		mid = (start + end) / 2;
	}

	return false;
}

int main(){


	int findCnt;
	int findNum;
	cin >> cnt;

	for(int i = 0; i < cnt; ++i) cin >> arr[i];

	sort(arr, arr + cnt);

	cin >> findCnt;

	for(int j = 0; j < findCnt; ++j){
		cin >> findNum;
		cout << findAnswer(findNum) << endl;
	}

	return 0;
}
