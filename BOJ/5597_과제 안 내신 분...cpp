#include <iostream>
using namespace std;

bool check[31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	for (int i = 0; i < 28; ++i) {
		cin >> num;
		check[num] = true;
	}

	for (int i = 1; i <= 30; ++i) {
		if (!check[i])
			cout << i << '\n';
	}

	return 0;
}