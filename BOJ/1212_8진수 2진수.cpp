#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string eight;
	string two[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};

	cin >> eight;

	for (int i = 0; i < eight.length(); i++) {
		int temp = eight[i] - '0';
		if (i == 0)
			cout << stoi(two[temp]);
		else
			cout << two[temp];
	}

	return 0;
}
