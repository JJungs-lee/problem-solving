#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int arr[26] = {};
	for (auto c : s1) arr[c - 'a']++;
	for (auto c : s2) arr[c - 'a']--;

	int res = 0;
	for (int i : arr) {
		res += abs(i);
	}

	cout << res;

	return 0;
}