#include <iostream>
#include <algorithm>

using namespace std;
struct data {
	int first;
	int second;
};
const bool funtion(const data& a, const data& b) {
	return a.first < b.first;
}

int main() {
	int testCase;

	cin >> testCase;

	while(testCase--) {
		int n;
		cin >> n;

		data* d = new data[n];

		for(int i = 0; i < n; ++i) {
			cin >> d[i].first >> d[i].second;
		}
		sort(d, d + n, funtion);

		int cnt = 1;
		int min = d[0].second;
		for(int i = 1; i < n; ++i) {
			if(d[i].second < min) {
				min = d[i].second;
				cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}