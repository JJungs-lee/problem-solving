#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	getline(cin, str);

	const string compare_str = "UCPC";
	int idx = 0;
	for (auto c : str) {
		if (compare_str[idx] == c) {
			idx++;
		}
	}
	if (idx == 4)
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";
	return 0;
}