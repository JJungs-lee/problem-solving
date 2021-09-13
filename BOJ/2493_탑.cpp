#include <cstring>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n, num;
	scanf("%d", &n);

	vector<int> v;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		v.push_back(num);
	}

	vector<int> NGE(v.size(), 0);
	stack<int> s;

	for (int idx = v.size() - 1; idx >= 0; --idx) {
		while (!s.empty() && v[s.top()] < v[idx]) {
			NGE[s.top()] = idx + 1;
			s.pop();
		}
		s.push(idx);
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", NGE[i]);

	return 0;
}
