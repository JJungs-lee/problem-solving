#include <iostream>

using namespace std;

int main() {
	long long int cache[102];
	int testCase;
	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 1;
	cache[3] = 2;
	cache[4] = 2;

	for (int i = 5; i < 101; ++i) {
		cache[i] = cache[i - 5] + cache[i - 1];
	}

	cin >> testCase;

	while (testCase--) {
		int num;
		cin >> num;

		cout << cache[num - 1] << endl;
	}

	return 0;
}