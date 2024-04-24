#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, res = 0;
	cin >> n;

	while (n--) {
		string str;
		cin >> str;
		stack<char> s;

		for (char c : str) {
			if (!s.empty() && s.top() == c)
				s.pop();
			else
				s.push(c);
		}

		if (s.empty())
			res++;
	}

	cout << res;

	return 0;
}