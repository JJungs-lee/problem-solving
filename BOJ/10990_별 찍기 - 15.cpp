#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = n; i > 0; i--) {
		for (int j = i - 2; j >= 0; j--) {
			printf(" ");
		}
		printf("*");
		for (int j = 2 * (n - i) - 1; j > 0; j--) {
			printf(" ");
		}
		if (i < n)
			printf("*");
		printf("\n");
	}

	return 0;
}