#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x, y;
	cin >> n;

	int arr[6] = {
	    0,
	};
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		if (x == 0 || y == 0)
			arr[5]++;
		else if (x > 0 && y > 0)
			arr[1]++;
		else if (x < 0 && y > 0)
			arr[2]++;
		else if (x < 0 && y < 0)
			arr[3]++;
		else if (x > 0 && y < 0)
			arr[4]++;
	}

	for (int i = 1; i < 6; ++i) {
		if (i == 5)
			cout << "AXIS: ";
		else
			cout << "Q" << i << ": ";
		cout << arr[i] << '\n';
	}
	return 0;
}