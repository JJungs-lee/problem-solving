#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int candy, people;
		cin >> candy >> people;
		cout << "You get " << candy / people << " piece(s) and your dad gets " << candy % people << " piece(s).\n";
	}

	return 0;
}