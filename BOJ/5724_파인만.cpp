#include <cmath>  //pow
#include <iostream>

using namespace std;

int cache[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	// init()
	for (int i = 1; i < 101; i++) {
		cache[i] = pow(i, 2);
	}
	// slove()
	//  갯수가 1의 제곱부터 그 해당수의 제곱을 모두 더한값이라서
	//  단순하게 저장해둔값을 for문 돌면서 더함.
	while (cin >> n) {
		if (n == 0) break;

		int sum = 0;
		for (int i = 1; i <= n; ++i) sum += cache[i];
		cout << sum << endl;
	}

	return 0;
}