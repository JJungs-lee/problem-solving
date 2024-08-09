#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string findstr = "666";
	int how_many;
	cin >> how_many;

	int count = 0;
	int num = 665;
	while (true) {
		if (to_string(num).find(findstr) != string::npos)
			count++;

		if (count == how_many) {
			cout << num;
			break;
		}
		num++;
	}
	return 0;
}