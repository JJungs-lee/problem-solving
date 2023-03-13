#include <iostream>

using namespace std;

int main() {
	int n;
	int sum = 1;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		int muti;
		cin >> muti;
		sum += (muti - 1);
	}
	cout << sum << endl;

	return 0;
}
