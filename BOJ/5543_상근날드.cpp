#include <algorithm>
#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[5];
	int minHam = 5000;
	int minDrink = 5000;

	for (int i = 0; i < 5; ++i) cin >> arr[i];

	minHam = min(arr[0], min(arr[1], arr[2]));
	minDrink = min(arr[3], arr[4]);

	cout << minHam + minDrink - 50;

	return 0;
}