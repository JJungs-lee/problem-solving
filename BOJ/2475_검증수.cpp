#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int res = 0;
	for (int i = 0; i < 5; ++i) {
		cin >> n;
		res += n * n;
	}
	cout << res % 10;
	
	return 0;
}