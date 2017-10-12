#include <iostream>
using namespace std;

int comb(int n, int r)
{
	int result = 1;
	int i;
	if(n - r < r)
		r = n - r;
	for(i = 1; i <= r; i++)
	{
		result *= (n - r + i);
		result /= i;
	}
	return result;
}

int main() {

	int testCase;
	cin >> testCase;

	while(testCase--){
		int n;
		int r;
		cin >> r >> n;

		cout << comb(n, r) << endl;
	}
	return 0;
}