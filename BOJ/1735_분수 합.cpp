#include <iostream>

using namespace std;

struct fountain {
	int mother;
	int sun;
};

int findGCD(int sun, int mother);

int main() {
	fountain f[2];
	int sun;
	int mother;
	int gcd;

	//		a			b				c				d
	cin >> f[0].sun >> f[0].mother >> f[1].sun >> f[1].mother;
	// ad + cd    sun
	// ------- = -------
	//    bd      mother
	sun = (f[0].sun * f[1].mother + f[1].sun * f[0].mother);
	mother = (f[0].mother * f[1].mother);

	gcd = findGCD(sun, mother);

	cout << sun / gcd << ' ' << mother / gcd << endl;

	return 0;
}

int findGCD(int a, int b) {
	if (a < b) return findGCD(b, a);
	if (b == 0) return a;
	return findGCD(b, a % b);
}
