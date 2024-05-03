#include <iostream>

using namespace std;

int main() {
	int jumsu[4];
	int numOfVic = 0;
	int maxJumsu = -1;

	for (int i = 0; i < 5; ++i) {
		cin >> jumsu[0] >> jumsu[1] >> jumsu[2] >> jumsu[3];
		int sum = jumsu[0] + jumsu[1] + jumsu[2] + jumsu[3];

		if (maxJumsu < sum) {
			maxJumsu = sum;
			numOfVic = i;
		}
	}
	cout << numOfVic + 1 << ' ' << maxJumsu;
	return 0;
}