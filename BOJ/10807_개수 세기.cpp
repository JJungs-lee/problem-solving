#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	int arr[201] = {};

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> num;
		arr[num + 100]++;
	}
	cin >> num;
	cout << arr[num + 100];

	return 0;
}