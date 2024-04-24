#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];

	sort(v.begin(), v.end());
	for (int num : v)
		cout << num << " ";

	return 0;
}