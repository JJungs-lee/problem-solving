#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(80001);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	stack<int> s;
	unsigned long long res = 0;
	for (int i = 0; i < n; ++i) {
		while (!s.empty() && s.top() <= v[i])
			s.pop();

		res += s.size();
		s.push(v[i]);
	}
	cout << res << '\n';

	return 0;
}