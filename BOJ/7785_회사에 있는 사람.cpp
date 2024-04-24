#include <iostream>
#include <map>
#include <string>

using namespace std;

struct compare {
	bool operator()(const string& a, const string& b) const {
		return a > b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	map<string, bool, compare> m;
	for (int i = 0; i < n; ++i) {
		string name, state;
		cin >> name >> state;

		if (state == "enter")
			m[name] = true;
		else
			m[name] = false;
	}

	for (auto iter : m)
		if (iter.second)
			cout << iter.first << "\n";

	return 0;
}