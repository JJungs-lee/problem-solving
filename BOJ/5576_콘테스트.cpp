#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v1, v2;
	int num;
	for(int i = 0; i < 10; ++i) {
		cin >> num;
		v1.push_back(num);
	}
	for(int i = 0; i < 10; ++i) {
		cin >> num;
		v2.push_back(num);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	cout << (v1[9] + v1[8] + v1[7]) << " " << (v2[9] + v2[8] + v2[7]) << endl;
	return 0;
}