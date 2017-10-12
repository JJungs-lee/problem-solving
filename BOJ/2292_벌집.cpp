#include <iostream>

using namespace std;

int main() {
	unsigned int n;
	cin >> n;

	unsigned int arr[20001] = { 1, };


	for(int i = 1; i < 20001; ++i) {
		arr[i] = arr[i - 1] + 6 * i;
	}


	for(int i = 0; i < 20000; ++i) {
		if(n == 1) {
			cout << '1' << endl;
			break;
		}

		if(arr[i] < n && n <= arr[i + 1]) {
			cout << i + 2 << endl;
			break;
		}
	}

	return 0;
}