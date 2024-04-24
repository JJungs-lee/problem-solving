#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;

	string logger;
	while (tc--) {
		cin >> logger;
		list<char> l;
		auto iter = l.begin();

		for (char c : logger) {
			if (isalpha(c) || isdigit(c)) {
				l.insert(iter, c);
			} else if (c == '<') {
				if (iter != l.begin()) iter--;
			} else if (c == '>') {
				if (iter != l.end()) ++iter;
			} else if (c == '-') {
				if (iter != l.begin()) {
					iter--;
					iter = l.erase(iter);
				}
			}
		}
		for (auto it : l)
			cout << it;
		cout << "\n";
	}

	return 0;
}