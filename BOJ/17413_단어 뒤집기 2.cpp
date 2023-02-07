#include <iostream>
#include <stack>
#include <string>
using namespace std;

void printStack(stack<char> &s) {
	while (s.size()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	string str;

	getline(cin, str);

	stack<char> s;
	bool flag = false;
	for (char c : str) {
		if (flag) {
			cout << c;
			if (c == '>')
				flag = false;
		} else {
			if (c == '<')
				flag = true;

			if (c == '<' || c == ' ') {
				printStack(s);
				cout << c;
				continue;
			}
			s.push(c);
		}
	}

	printStack(s);

	return 0;
}