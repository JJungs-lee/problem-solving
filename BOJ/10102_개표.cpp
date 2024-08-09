#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int v;
	string str;
	cin >> v >> str;

	int A = 0, B = 0;
	for (int i = 0; i < v; ++i) {
		if (str[i] == 'A')
			A++;
		else if (str[i] == 'B')
			B++;
	}

	if (A == B)
		cout << "Tie";
	else if (A > B)
		cout << "A";
	else
		cout << "B";
	return 0;
}