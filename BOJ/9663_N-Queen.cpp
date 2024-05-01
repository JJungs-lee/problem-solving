#if 0
#include <stdio.h>
#define SIZE 15
#define MY_ABS(x) ((x)< 0? (-(x)): (x))
int n;
int queen[SIZE];
int cnt = 0;

void backtracking(int level) {

	bool ko = true;
	if (level == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; ++i) {
		//겹치지 않으면 그자리에 넣어줌.
		ko = true;
		for (int j = 0; j < level; j++) {
			// queen[j] == i 의 의미는 같은 X값에 있을때 스킵
			//printf("queen[j] == i >> %d     %d\n", queen[j],i);
			//printf("MY_ABS(level - j)  >> %d\n", MY_ABS(level - j));
			//printf("MY_ABS(level - j)  >> %d\n", MY_ABS(i - queen[j]));
			if (queen[j] == i || MY_ABS(level - j) == MY_ABS(i - queen[j])) {
				ko = 0;
				break;
			}
		}
		if (ko) {
			queen[level] = i;
			backtracking(level + 1);
		}

	}
}
int main() {

	scanf("%d", &n);

	//init
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		queen[i] = 0;
	}

	backtracking(0);

	printf("%d\n", cnt);

	return 0;
}
#endif

#include <iostream>
using namespace std;

bool isused1[40];	// y
bool isused2[40];	// x + y
bool isused3[40];	// x - y + n - 1

int n;
int res = 0;

void func(int cur) {
	if (cur == n) {
		res++;
		return;
	}
	for (int i = 0; i < n; ++i) {	// i == y, cur == x
		if (isused1[i] || isused2[cur + i] || isused3[cur - i + n - 1])
			continue;
		
		isused1[i] = true;
		isused2[cur + i] = true;
		isused3[cur - i + n - 1] = true;
		func(cur + 1);
		isused3[cur - i + n - 1] = false;
		isused2[cur + i] = false;
		isused1[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	func(0);
	cout << res;
	return 0;
}