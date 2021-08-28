#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
	int n, num;
	unordered_map<int, int> hash;

	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		hash[num] = 1;
	}

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		if (hash[num]) {
			printf("1 ");
		} else {
			printf("0 ");
		}
	}
	return 0;
}