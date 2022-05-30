#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	stack<int> s;
	int res = 0;
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && v[s.top()] >= v[i]) {
			int h = v[s.top()];
			s.pop();
			int l = s.empty() ? -1 : s.top();
			res = max(res, (i - l - 1) * h);
		}
		s.push(i);
	}
	while (!s.empty()) {
		int h = v[s.top()];
		s.pop();
		int l = s.empty() ? -1 : s.top();
		res = max(res, (n - l - 1) * h);
	}
	cout << res << endl;

	return 0;
}
