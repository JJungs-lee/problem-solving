#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	cin >> a >> b;

	if (a > b)
		swap(a, b);

	if (a == b || b - a == 1)
		cout << 0;
	else {
		cout << b - a - 1 << "\n";
		for (long long i = a + 1; i < b; i++)
			cout << i << " ";
	}

	return 0;
}