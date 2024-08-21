#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int sum = 0;
	for (int i = 0; i < n + 1; ++i) {
		for (int j = i; j < n + 1; ++j) {
			sum += (i + j);
		}
	}
	cout << sum;

	return 0;
}