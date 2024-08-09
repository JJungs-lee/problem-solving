#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int res = 0;
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		int in, out;
		cin >> out >> in;
		sum -= out;
		sum += in;

		res = max(res, sum);
	}

	cout << res;

	return 0;
}