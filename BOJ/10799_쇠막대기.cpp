#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;

	cin >> str;

	stack<char> s;
	int res = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(') {
			s.push(str[i]);
		} else if (i - 1 >= 0 && str[i - 1] == '(') {
			s.pop();
			res += s.size();
		} else {
			s.pop();
			res++;
		}
	}
	cout << res << endl;

	return 0;
}
