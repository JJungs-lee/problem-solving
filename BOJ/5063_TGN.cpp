#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		int r;  // 광고안했을때 돈
		int e;  // 광고할때 돈
		int c;  // 광고 비용

		cin >> r >> e >> c;

		if (r < e - c)
			cout << "advertise" << endl;
		else if (r == e - c)
			cout << "does not matter" << endl;
		else
			cout << "do not advertise" << endl;
	}

	return 0;
}