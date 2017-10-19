#include <iostream>

using namespace std;

int main() {

	int testCase;

	cin >> testCase;

	while(testCase--) {
		long long a, b;
		long long num = 1;

		cin >> a >> b;

		for(int i = 0; i<b; ++i) {
			num *= a;
			num %= 10;
		}
		if(num == 0) num = 10;
		cout << num << endl;
	}

	return 0;
}