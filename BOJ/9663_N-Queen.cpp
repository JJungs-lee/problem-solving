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
