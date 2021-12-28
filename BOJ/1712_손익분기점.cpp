#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	if (b >= c)
		cout << "-1\n";
	else
		cout << a / (c - b) + 1 << '\n';

	return 0;
}
