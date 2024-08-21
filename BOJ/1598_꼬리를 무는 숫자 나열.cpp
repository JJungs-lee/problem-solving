#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;

	cin >> a >> b;
	a -= 1;
	b -= 1;

	int x = abs(a / 4 - b / 4);
	int y = abs(a % 4 - b % 4);

	cout << x + y;

	return 0;
}