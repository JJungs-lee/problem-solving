#include <stdio.h>

int main() {
	int ret;
	int minus;
	int i;

	scanf("%d", &ret);

	for (i = 0; i < 9; ++i) {
		scanf("%d", &minus);
		ret -= minus;
	}

	printf("%d", ret);

	return 0;
}