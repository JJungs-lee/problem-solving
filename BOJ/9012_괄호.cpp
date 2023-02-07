#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	int tc;

	cin >> tc;

	while (tc--) {
		string str;
		stack<char> s;

		cin >> str;
		bool flag = true;
		for (auto c : str) {
			if (c == '(') {
				s.push('(');
			} else if (c == ')') {
				if (!s.empty()) {
					s.pop();
				} else {
					flag = false;
					break;
				}
			}
		}
		flag&& s.empty() ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}