#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	while (true) {
		cin >> num;
		if (num == -1)
			break;

		vector<int> v;
		int perfect = 0;
		for (int i = 1; i < num; ++i) {
			if (num % i == 0) {
				v.push_back(i);
				perfect += i;
			}
		}

		if (perfect == num) {
			cout << num << " = ";
			for (int i = 0; i < v.size() - 1; ++i) {
				cout << v[i] << " + ";
			}
			cout << v[v.size() - 1] << '\n';
		} else {
			cout << num << " is NOT perfect.\n";
		}
	}

	return 0;
}