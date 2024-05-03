#include <algorithm>
#include <iostream>
using namespace std;

char AdrianArr[3] = {'A', 'B', 'C'};                // 상근
char BrunoArr[4] = {'B', 'A', 'B', 'C'};            // 창영
char GoranArr[6] = {'C', 'C', 'A', 'A', 'B', 'B'};  // 현진

struct data {
	char* name;
	int count;
};

bool isCompare(const data& a, const data& b) { return a.count > b.count; }
int main() {
	int n;
	char que[101];
	data d[3];

	d[0].name = "Adrian";
	d[0].count = 0;
	d[1].name = "Bruno";
	d[1].count = 0;
	d[2].name = "Goran";
	d[2].count = 0;

	cin >> n;

	cin >> que;

	for (int i = 0; i < n; ++i) {
		if (que[i] == AdrianArr[i % 3]) d[0].count++;
		if (que[i] == BrunoArr[i % 4]) d[1].count++;
		if (que[i] == GoranArr[i % 6]) d[2].count++;
	}

	if (d[0].count == d[1].count && d[1].count == d[2].count) {
		// 3명이 다맞을때
		cout << d[0].count << endl;
		cout << d[0].name << endl;
		cout << d[1].name << endl;
		cout << d[2].name << endl;
	} else if (d[0].count == d[1].count && d[0].count > d[2].count) {
		// 1번과 2번이 맞을때
		cout << d[0].count << endl;
		cout << d[0].name << endl;
		cout << d[1].name << endl;
	} else if (d[1].count == d[2].count && d[0].count < d[1].count) {
		// 2번과 3번이 맞을때
		cout << d[1].count << endl;
		cout << d[1].name << endl;
		cout << d[2].name << endl;
	} else if (d[0].count == d[2].count && d[0].count > d[1].count) {
		// 1번과 3번이 맞을때
		cout << d[0].count << endl;
		cout << d[0].name << endl;
		cout << d[2].name << endl;
	} else {
		sort(d, d + 3, isCompare);
		cout << d[0].count << endl;
		cout << d[0].name << endl;
	}

	return 0;
}