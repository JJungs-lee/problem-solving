#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		bool alpha[26] = { 0, };
		int sum = 2015;
		string str;
		cin >> str;
		for (auto c : str) {
			if (!alpha[c - 'A']) {
				sum -= c;
				alpha[c - 'A'] = true;
			}
		}
		cout << sum << '\n';
	}

	return 0;
}