#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int main() {
	int num, n;
	char str_temp[1000];
	string str;
	queue<int> q;

	scanf("%d", &n);

	while (n--) {
		scanf("%s", str_temp);
		str = str_temp;
		if (str == "push") {
			scanf("%d", &num);
			q.push(num);
		} else if (str == "pop") {
			if (q.empty()) {
				printf("-1\n");
			} else {
				printf("%d\n", q.front());
				q.pop();
			}
		} else if (str == "size") {
			printf("%d\n", q.size());
		} else if (str == "empty") {
			printf("%d\n", (q.empty() ? 1 : 0));
		} else if (str == "front") {
			printf("%d\n", (q.empty() ? -1 : q.front()));
		} else if (str == "back") {
			printf("%d\n", (q.empty() ? -1 : q.back()));
		}
	}

	return 0;
}