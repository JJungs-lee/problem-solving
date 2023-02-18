#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k;
	cin >> k;

	int res = 0;
	stack<int> s;

	while (k--) {
		int num;
		cin >> num;

		res += num;

		if (!num) {
			res -= s.top();
			s.pop();
		} else {
			s.push(num);
		}
	}
	cout << res << '\n';

	return 0;
}