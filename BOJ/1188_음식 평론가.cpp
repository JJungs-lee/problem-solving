#include <algorithm>
#include <iostream>
using namespace std;

int GCD(int a, int b) {
	if (a % b == 0)
		return b;
	return GCD(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	cout << m - GCD(n, m);
	return 0;
}
