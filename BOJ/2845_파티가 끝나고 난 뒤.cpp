#include <iostream>

using namespace std;

int main() {
	int l;  // 사람수
	int p;  // 넓이
	int arr[5];

	cin >> l >> p;
	int num;
	for (int i = 0; i < 5; ++i) {
		cin >> num;
		arr[i] = num - l * p;
	}

	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << ' ';
	}

	return 0;
}