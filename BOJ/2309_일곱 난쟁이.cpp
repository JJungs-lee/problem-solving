#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int sum = 0;
	int arr[9];
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (int i = 0; i < 8; ++i) {
		for (int j = i + 1; j < 9; ++j) {
			if (arr[i] + arr[j] == sum - 100) {
				arr[i] = arr[j] = 200;
				goto ans;
			}
		}
	}
ans:
	sort(arr, arr + 9);
	for(int i = 0; i < 7; ++i)
		cout << arr[i] << endl;

	return 0;
}