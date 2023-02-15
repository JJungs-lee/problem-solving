#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	string b;
	long long sum = 0;
	long long bSum = 0;

	cin >> a >> b;

	for (int i = 0; i < b.size(); ++i) {
		bSum += (b[i] - '0');
	}

	for (int i = 0; i < a.size(); ++i) {
		sum += (a[i] - '0');
	}
	cout << sum * bSum << endl;

	return 0;
}