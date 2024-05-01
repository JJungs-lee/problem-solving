#include <iostream>
using namespace std;

void hanoi(int s, int e, int n) {
	if (n == 1) {
		cout << s << " " << e << '\n';
		return;
	}
	hanoi(s, 6 - s - e, n - 1);
	cout << s << " " << e << '\n';
	hanoi(6 - s - e, e, n - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);

	return 0;
}