#include <iostream>

using namespace std;

int main() {
	int n;
	unsigned long long sum = 0;
	cin >> n;

	for (int i = 1; i < n; ++i) {
		sum += i * (n + 1);
	}
	cout << sum << endl;
	return 0;
}