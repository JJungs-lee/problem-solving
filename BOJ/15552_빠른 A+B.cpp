#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;
	int tc;

	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}