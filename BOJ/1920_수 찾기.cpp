#include <algorithm>
#include <iostream>

using namespace std;
int cnt;
int arr[100001];

int findAnswer(int findNum) {
	int start = 0;
	int end = cnt - 1;
	int mid = (start + end) / 2;

	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == findNum)
			return true;
		else if (arr[mid] < findNum)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return false;
}

int main() {
	int findCnt;
	int findNum;
	
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i) 
		scanf("%d", &arr[i]);

	sort(arr, arr + cnt);

	scanf("%d", &findCnt);

	for (int j = 0; j < findCnt; ++j) {
		scanf("%d", &findNum);
		printf("%d\n",findAnswer(findNum));
	}

	return 0;
}
