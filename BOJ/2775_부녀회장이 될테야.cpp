#include <iostream>

using namespace std;

#define MAX_NUM 15
static int arr[MAX_NUM][MAX_NUM];

void make_answer() {
	for (int i = 0; i < MAX_NUM; ++i) {
		arr[0][i] = i;
	}

	for (int i = 1; i < MAX_NUM; ++i) {
		for (int j = 1; j < 15; ++j) {
			arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	int k, n;
	cin >> tc;

	make_answer();
	while (tc--) {
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}

	return 0;
}
