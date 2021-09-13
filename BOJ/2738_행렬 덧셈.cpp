#include <iostream>

using namespace std;

int main() {
	int n, m;
	int arr[100][100];

	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int num;
			cin >> num;
			arr[i][j] += num;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}