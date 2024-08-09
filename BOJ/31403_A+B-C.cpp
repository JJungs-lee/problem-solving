#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	cout << a + b - c << '\n';
	cout << stoi(to_string(a) + to_string(b)) - c << '\n';

	return 0;
}