#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a;

	scanf("%d", &a);
	printf("%d", (a % 4 == 0 && a % 100 != 0) || a % 400 == 0);

	return 0;
}