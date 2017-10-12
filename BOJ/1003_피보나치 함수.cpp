#include <iostream>

using namespace std;
int onecount = 0;
int zerocount = 0;
int fibonacci(int n);

int main(){
	int testCase;

	cin >> testCase;

	while(testCase--){
		int n;

		cin >> n;

		fibonacci(n);

		cout << zerocount << ' ' << onecount << endl;
		onecount = 0;
		zerocount = 0;
	}


	return 0;
}

int fibonacci(int n) {
	if(n == 0) {
		zerocount++;
		return 0;
	} else if(n == 1) {
		onecount++;
		return 1;
	}

	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}