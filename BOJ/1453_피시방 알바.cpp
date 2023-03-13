#include <iostream>

using namespace std;

bool area[100] = { false, };

int main() {
	int n;
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (area[num - 1] == false) {
			area[num - 1] = true;
		} else
			count++;
	}

	cout << count << endl;

	return 0;
}