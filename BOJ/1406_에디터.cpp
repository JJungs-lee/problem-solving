#include <iostream>
#include <list>
#include <string>

using namespace std;
void print_list(auto lt) {
	for (auto l : lt)
		cout << l;
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;

	int m;
	cin >> m;
	
	list<char> res;
	for (char c : str)
		res.push_back(c);

	list<char>::iterator iter = res.end();
	for (int i = 0; i < m; ++i) {
		char cmd, c;
		cin >> cmd;

		switch(cmd) {
			case 'L':
				if (iter != res.begin())
					iter--;
				break;
			case 'D':
				if (iter != res.end())
					iter++;
				break;
			case 'B': {
				if (iter != res.begin()) {
					auto backup_iter = iter;
					iter--;
					res.erase(iter);
					iter = backup_iter;
				}
				break;
			}
			case 'P':
				cin >> c;
				res.insert(iter, c);
				break;
		}
	}
	print_list(res);
	return 0;
}