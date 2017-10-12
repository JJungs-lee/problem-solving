#include <iostream>
#include <string>

using namespace std;

int main() {
	int m, d;
	int pos = 0;
	string str[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cin >> m >> d;
	int sum = 0;
	for(int i = 0; i < m - 1; ++i) {
		sum += day[i];
	}
	sum += d;

	pos += (sum % 7);
	cout << str[pos % 7] << endl;
	return 0;
}