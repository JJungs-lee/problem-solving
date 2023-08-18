#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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
	cout << res << '\n';

	return 0;
}
