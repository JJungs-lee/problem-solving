#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int tc, n;
	char str[21];
	scanf("%d", &tc);

	while (tc--) {
		int idx = 0;
		scanf("%d %s", &n, str);
		while (str[idx] != '\0') {
			for (int i = 0; i < n; ++i)
				printf("%c", str[idx]);
			idx++;
		}
		printf("\n");
	}

	return 0;
}