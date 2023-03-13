#include <algorithm>
#include <iostream>
using namespace std;

int n;
int func(int num) {
	if (num > n) {
		return num / 10;
	}
	return max(func(num * 10 + 4), func(num * 10 + 7));
}

int main() {
	cin >> n;

	cout << func(0);
	return 0;
}