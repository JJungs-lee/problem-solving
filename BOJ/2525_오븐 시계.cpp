#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	int carry = 0;

	cin >> A >> B >> C;

	B += C;
	if (B >= 60) {
		carry = B / 60;
		B -= carry * 60;
	}

	if (carry) {
		A += carry;
		if (A >= 24) {
			A -= 24;
		}
	}
	cout << A << " " << B;

	return 0;
}
