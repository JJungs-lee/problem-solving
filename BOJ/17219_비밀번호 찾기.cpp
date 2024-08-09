#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	unordered_map<string, string> hash;
	string site, pass;
	while (n--) {
		cin >> site >> pass;
		hash[site] = pass;
	}

	while (m--) {
		cin >> site;
		cout << hash[site] << '\n';
	}

	return 0;
}
