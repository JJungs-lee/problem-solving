#include <iostream>
#include <string>

using namespace std;

int h, w, n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	
	while (tc--) {
		string res;
		cin >> h >> w >> n;
		int floor = n % h;
		int room = n / h + 1;

		if (floor == 0) {
			floor = h;
			room = n / h;
		}
		
		cout << floor * 100 + room << '\n';
	}
	return 0;
}