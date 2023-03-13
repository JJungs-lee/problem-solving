#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
	char strNum[100];
	char *pEnd;
	cin >> strNum;

	cout << strtol(strNum, &pEnd, 16);

	return 0;
}