#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b);

int main() {
	int testCase;
	int m, n, x, y;
	
	cin >> testCase;

	while(testCase--) { 
		cin >> m >> n >> x >> y;
		bool flag = false;
		int gcdNum = m > n ? gcd(m, n) : gcd(n, m);
		int lcdNum = (m*n) /gcdNum;
		int tempX = x, tempY = y;
		while(tempX < lcdNum && tempY < lcdNum) {
			if(tempX < tempY) {
				tempX += m;
			} else if(tempX > tempY){
				tempY += n;
			} else {
				cout << tempX << endl;
				flag = true;
				break;
			}
		}
		if(!flag) cout << "-1" << endl;
	}
	return 0;
}

int gcd(int a, int b) {
	if(b==0) return a;
	gcd(b, a%b);
}
