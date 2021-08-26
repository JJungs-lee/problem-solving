#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
	int n;
	unordered_map<int, int> hash;

	for (int i = 0; i < 10; ++i) {
		scanf("%d", &n);
		hash[n % 42]++;
	}

	printf("%d", hash.size());

	return 0;
}