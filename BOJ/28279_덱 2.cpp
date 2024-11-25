#include <deque>
#include <iostream>
using namespace std;

deque<int> dq;

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int num;
		int input;

		cin >> num;

		switch (num) {
			case 1:
				cin >> input;
				dq.push_front(input);
				break;
			case 2:
				cin >> input;
				dq.push_back(input);
				break;
			case 3:
				if (dq.empty()) {
					cout << "-1\n";
				} else {
					cout << dq.front() << '\n';
					dq.pop_front();
				}
				break;
			case 4:
				if (dq.empty()) {
					cout << "-1\n";
				} else {
					cout << dq.back() << '\n';
					dq.pop_back();
				}
				break;
			case 5:
				cout << dq.size() << "\n";
				break;
			case 6:
				if (dq.empty())
					cout << "1\n";
				else
					cout << "0\n";
				break;
			case 7:
				if (dq.empty())
					cout << "-1\n";
				else
					cout << dq.front() << '\n';
				break;
			case 8:
				if (dq.empty())
					cout << "-1\n";
				else
					cout << dq.back() << '\n';
				break;
		}
	}

	return 0;
}