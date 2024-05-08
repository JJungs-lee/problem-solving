#include <iostream>
using namespace std;

bool arr[2000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, num;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		arr[num + 1000000] = true;
	}

	for (int i = 2000000; i >= 0; --i) {
		if (arr[i])
			cout << i - 1000000 << '\n';
	}

	return 0;
}