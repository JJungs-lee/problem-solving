//
#include <iostream>

using namespace std;

long long mul(long long x, long long y, long long p) {
	long long ans = 1;
	while(y > 0) {
		if(y % 2 != 0) {
			ans *= x;
			ans %= p;
		}
		x *= x;
		x %= p;
		y /= 2;
	}
	return ans;
}

int main() {
	
	long long a, b, c;
	cin >> a >> b >> c;

	cout << mul(a, b, c);

	return 0;
}