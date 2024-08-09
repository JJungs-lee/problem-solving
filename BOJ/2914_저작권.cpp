#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int cnt, aver;
	cin >> cnt >> aver;

	cout << (aver - 1) * cnt + 1;
	return 0;
}