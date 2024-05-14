#include <iostream>
#include <string>

using namespace std;

int reverse(int num);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int n;
		int sum = 0;
		cin >> n;
		sum = n + reverse(n);

		if (sum == reverse(sum)) {
			cout << "YES" << endl;
		} else
			cout << "NO" << endl;
	}

	return 0;
}

int reverse(int num) {
	int ret = 0;

	while (num > 0) {
		ret *= 10;
		ret += num % 10;
		num /= 10;
	}

	return ret;
}