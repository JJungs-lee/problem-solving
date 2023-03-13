#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	char two[1000001];
	vector<int> bin;

	int sum = 0;
	int count = 0;
	cin >> two;

	for (int i = strlen(two) - 1; i >= 0; --i) {
		if (count == 0) {
			sum += (two[i] - '0') * pow(2, 0);
			count++;
			if (i == 0) bin.push_back(sum);

		} else if (count == 1) {
			sum += (two[i] - '0') * pow(2, 1);
			count++;
			if (i == 0) bin.push_back(sum);

		} else {
			sum += (two[i] - '0') * pow(2, 2);
			bin.push_back(sum);
			count = 0;
			sum = 0;
		}
	}

	for (int i = bin.size() - 1; i >= 0; --i) {
		cout << bin[i];
	}

	return 0;
}