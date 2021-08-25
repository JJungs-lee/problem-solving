#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int tc;
	int a, b;

	scanf("%d", &tc);
	for (int i = 1; i <= tc; ++i) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n", i, a, b, a + b);
	}

	return 0;
}