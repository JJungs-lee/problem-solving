#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int main() {
	int n, m;
	int num;
	unordered_map<int, int> u;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		unordered_map<int, int>::iterator iter = u.find(num);
		if (iter == u.end()) {
			u.insert({num, 1});
		} else {
			iter->second++;
		}
	}

	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d", &num);
		unordered_map<int, int>::iterator iter = u.find(num);
		if (iter == u.end()) {
			printf("0 ");
		} else {
			printf("%d ", iter->second); 
		}
	}

	return 0;
}