#include <cmath>
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int school_num;
	cin >> school_num;

	int student, apple;
	int res = 0;
	for (int i = 0; i < school_num; ++i) {
		cin >> apple >> student;
		res += student % apple;
	}
	cout << res;
	return 0;
}