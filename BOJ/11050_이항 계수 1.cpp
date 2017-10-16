#include <iostream>

using namespace std;

long long binomialCoefficient(int n,int r) {
	
	if(r == 0 || n == r) {
		return 1;
	}
	return binomialCoefficient(n - 1, r - 1) + binomialCoefficient(n - 1, r);
}

int main() {
	int n, k;

	cin >> n >> k;

	cout << binomialCoefficient(n, k);
	return 0;
}