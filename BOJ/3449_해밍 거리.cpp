#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int twoToTen(string str);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCase;

	cin >> testCase;

	while (testCase--) {
		int cnt = 0;
		string str1;
		string str2;

		cin >> str1 >> str2;

		for (int i = 0; i < str1.size(); ++i) {
			if (str1[i] != str2[i]) cnt++;
		}
		cout << "Hamming distance is " << cnt << '.' << endl;
	}
	return 0;
}
