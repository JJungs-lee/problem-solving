#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	stack<char> s;
	int res = 0;

	int temp = 1;
	for (int i = 0; i < str.size(); ++i) {
		char c = str[i];

		if (c == '(') {
			temp *= 2;
			s.push(c);
		} else if (c == '[') {
			temp *= 3;
			s.push(c);
		} else {
			if (s.empty() ||
			    (c == ')' && s.top() != '(') ||
			    (c == ']' && s.top() != '[')) {
				res = 0;
				break;
			}

			if (c == ')') {
				if (str[i - 1] == '(')
					res += temp;
				temp /= 2;
			} else {
				if (str[i - 1] == '[')
					res += temp;
				temp /= 3;
			}
			s.pop();
		}
	}

	if (!s.empty())
		res = 0;

	cout << res;

	return 0;
}
