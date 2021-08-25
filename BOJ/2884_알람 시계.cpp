#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	if (b < 45) {
		a -= 1;
		b += 60;
		if (a == -1)
			a = 23;
	} 
	b -= 45;
	printf("%d %d", a, b);

	return 0;
}