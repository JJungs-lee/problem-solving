#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, num;
	cin >> n >> x;
	while (n--) {
		cin >> num;
		if (num < x) {
			cout << num << " ";
		}
	}
	return 0;
}