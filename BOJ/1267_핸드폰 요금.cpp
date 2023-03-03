#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int arr[21];

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int Y = 0, M = 0;
	for (int i = 0; i < n; ++i) {
		Y += (1 + arr[i] / 30);
		M += (1 + arr[i] / 60);
	}

	Y *= 10;
	M *= 15;

	if (Y == M)
		cout << "Y M " << Y;
	else if (Y > M)
		cout << "M " << M;
	else
		cout << "Y " << Y;

	return 0;
}
