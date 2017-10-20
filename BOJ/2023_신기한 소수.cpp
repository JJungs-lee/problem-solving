#include <iostream>
#include <vector>

using namespace std;

int n;
void findAnswer(int num, int l);
bool isPrime(int num);

int main() {
	cin >> n;
	int arr[4] = { 2, 3, 5, 7 };

	for(int i = 0; i < 4; ++i) {
		findAnswer(arr[i],1);
	}
	return 0;
}
void findAnswer(int num, int l) {
	if(l == n) {
		cout << num << endl;
	}
	for(int i = 1; i < 10; ++i) {
		int temp = num * 10 + i;
		if(isPrime(temp)) {
			findAnswer(temp, l + 1);
		}
	}
}
bool isPrime(int num) {
	for(int i = 2; i*i <= num; ++i) {
		if(num%i == 0) return false;
	}
	return true;
}
