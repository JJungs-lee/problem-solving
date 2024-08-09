#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[3];

	cin >> arr[0] >> arr[1] >> arr[2];

	sort(arr, arr + 3);
	cout << arr[1];

	return 0;
}