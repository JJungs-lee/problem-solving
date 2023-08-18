#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	while (testCase--) {
		string str;
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			q.push(num);
		} else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << '\n';
				q.pop();
			} else {
				cout << "-1\n";
			}
		} else if (str == "size") {
			cout << q.size() << '\n';
		} else if (str == "empty") {
			q.empty() ? cout << "1\n" : cout << "0\n";
		} else if (str == "front") {
			if (!q.empty()) {
				cout << q.front() << '\n';
			} else {
				cout << "-1\n";
			}
		} else if (str == "back") {
			if (!q.empty()) {
				cout << q.back() << '\n';
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}