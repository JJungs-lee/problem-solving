#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	// 5분(300), 1분(60), 10초
	int arr[3] = {
	    0,
	};
	while (t > 9) {
		if (t >= 300) {
			arr[0] += t / 300;
			t %= 300;
		} else if (t >= 60) {
			arr[1] += t / 60;
			t %= 60;
		} else {
			arr[2] += t / 10;
			t %= 10;
		}
	}

	if (t != 0)
		cout << "-1";
	else
		cout << arr[0] << ' ' << arr[1] << ' ' << arr[2];

	return 0;
}