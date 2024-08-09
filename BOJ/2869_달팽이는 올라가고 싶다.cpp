#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, v;
	cin >> a >> b >> v;

	int count = (v - a) / (a - b);
	if ((v - a) % (a - b) == 0)
		count += 1;
	else
		count += 2;
	cout << count;

	return 0;
}