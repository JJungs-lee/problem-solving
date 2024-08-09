#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	while (true) {
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		cout << a + b << '\n';
	}
	return 0;
}