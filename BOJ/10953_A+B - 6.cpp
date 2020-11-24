#include <stdio.h>

int main() {
	int tc;
	int a, b;
	char c;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%c%d", &a, &c, &b);
		printf("%d\n", a + b);
	}
	return 0;
}