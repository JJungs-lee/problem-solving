#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

struct team {
	int get;
	int lost;
};

int teamCnt;
int playCnt;
team* t;

void cal() {
	long long maxNum, minNum;
	long long sum = 0;

	for (int i = 1; i < teamCnt + 1; ++i) {
		if (t[i].get == 0 && t[i].lost == 0) {
			sum = 0;
		} else {
			sum = (t[i].get * t[i].get) * 1000LL / (t[i].get * t[i].get + t[i].lost * t[i].lost);
		}
		if (i == 1) {
			maxNum = minNum = sum;
			continue;
		}
		maxNum = max(maxNum, sum);
		minNum = min(minNum, sum);
	}
	cout << maxNum << '\n'
	     << minNum << '\n';
}

int main() {
	int testCase;

	cin >> testCase;

	while (testCase--) {
		cin >> teamCnt >> playCnt;

		t = new team[teamCnt + 1];
		for (int i = 1; i < teamCnt + 1; ++i) {
			t[i].get = 0;
			t[i].lost = 0;
		}
		int a, b, p, q;

		for (int i = 0; i < playCnt; ++i) {
			cin >> a >> b >> p >> q;
			t[a].get += p;
			t[a].lost += q;
			t[b].get += q;
			t[b].lost += p;
		}
		cal();
	}

	return 0;
}