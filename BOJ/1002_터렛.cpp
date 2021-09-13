#include <cmath>
#include <iostream>
using namespace std;

struct point {
	int x;
	int y;
	int r;
};

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		point p1, p2;
		double d = 0;

		cin >> p1.x >> p1.y >> p1.r >> p2.x >> p2.y >> p2.r;
		double dis1 = p1.x - p2.x;
		double dis2 = p1.y - p2.y;

		d = sqrt(pow(dis1, 2.0) + pow(dis2, 2.0));
		if (p1.x == p2.x && p1.y == p2.y && p1.r == p2.r)
			cout << -1 << endl;

		else if (p1.r + p2.r < d || abs(p1.r - p2.r) > d)
			cout << 0 << endl;
		else if (p1.r + p2.r == d || abs(p1.r - p2.r) == d)
			cout << 1 << endl;
		else if (abs(p1.r - p2.r) < d && d < p1.r + p2.r)
			cout << 2 << endl;
	}

	return 0;
}
