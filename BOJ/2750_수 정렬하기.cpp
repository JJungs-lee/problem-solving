#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int n;
	int num;

	cin >> n;
	int arr[1001];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		cout << arr[i] << endl;
	}
	return 0;
}