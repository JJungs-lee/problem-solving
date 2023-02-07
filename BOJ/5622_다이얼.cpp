#include <stdio.h>

#include <iostream>
using namespace std;

int main() {
	string str;
	int res = 0;

	cin >> str;

	for (auto c : str) {
		switch (c) {
			case 'A':
			case 'B':
			case 'C':
				res += 3;
				break;
			case 'D':
			case 'E':
			case 'F':
				res += 4;
				break;
			case 'G':
			case 'H':
			case 'I':
				res += 5;
				break;
			case 'J':
			case 'K':
			case 'L':
				res += 6;
				break;
			case 'M':
			case 'N':
			case 'O':
				res += 7;
				break;
			case 'P':
			case 'Q':
			case 'R':
			case 'S':
				res += 8;
				break;
			case 'T':
			case 'U':
			case 'V':
				res += 9;
				break;
			case 'W':
			case 'X':
			case 'Y':
			case 'Z':
				res += 10;
				break;
		}
	}

	cout << res << endl;

	return 0;
}