#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int i = 2;
	while (n) {
		if (n == 1)
			break;

		if (n % i == 0) {
			n /= i;
			cout << i << '\n';
			i = 2;
		} else {
			i++;
		}
	}

	return 0;
}