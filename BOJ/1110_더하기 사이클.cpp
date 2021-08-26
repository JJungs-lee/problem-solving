#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int n, cur;
	int res = 0;

	scanf("%d", &n);

	cur = n;
	do {
		int a = cur / 10;
		int b = cur % 10;
		int c = (a + b) % 10;
		cur = b * 10 + c;
		res++;
	} while (n != cur);

	printf("%d", res);

	return 0;
}