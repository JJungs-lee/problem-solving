#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	unordered_map<long long, int> hash;
	long long num;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (hash.find(num) != hash.end())
			hash[num]++;
		else
			hash[num] = 1;
	}
	long long max_num = LONG_MIN;
	long long max_count = -1;
	for (auto iter = hash.begin(); iter != hash.end(); iter++) {
		if (max_count < iter->second) {
			max_count = iter->second;
			max_num = iter->first;
		} else if (max_count == iter->second && max_num > iter->first) {
			max_num = iter->first;
		}
	}
	cout << max_num << '\n';
	return 0;
}
