#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	while (true) {
		getline(cin, str);
		if (str == ".")
			break;

		stack<char> s;
		bool is_valid = true;
		for (char c : str) {
			if (c == '(' || c == '[') {
				s.push(c);
			} else if (c == ')') {
				if (s.empty() || s.top() != '(') {
					is_valid = false;
					break;
				}
				s.pop();
			} else if (c == ']') {
				if (s.empty() || s.top() != '[') {
					is_valid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty())
			is_valid = false;
		if (is_valid)
			cout << "yes\n";
		else
			cout << "no\n";
	}

	return 0;
}
