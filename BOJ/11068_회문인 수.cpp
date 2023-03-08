#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;
bool check();

int main() {
	int testCase;
	int num;
	cin >> testCase;

	while (testCase--) {
		int temp;
		bool flag = false;

		cin >> num;

		for (int B = 2; B < 65; ++B) {
			temp = num;
			flag = false;
			v.clear();

			// 진법 변환
			for (int i = 0; temp > 0; ++i) {
				v.push_back(temp % B);
				temp /= B;
			}
			if (check()) {
				cout << '1' << endl;
				flag = true;
				break;
			}
		}
		if (!flag) cout << '0' << endl;
	}

	return 0;
}

bool check() {
	for (int j = 0; j < v.size() / 2; ++j) {
		if (v[j] != v[v.size() - 1 - j]) {
			return false;
			break;
		}
	}
	return true;
}