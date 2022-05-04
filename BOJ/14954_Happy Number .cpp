#include <iostream>
#include <unordered_set>

using namespace std;

bool isHappy(int n) {
	int cur = n;
	unordered_set<int> hash;

	while (cur != 1) {
		int div_num = cur;
		int sum = 0;

		while (div_num) {
			sum += (div_num % 10) * (div_num % 10);
			div_num /= 10;
		}

		cur = sum;
		if (hash.find(cur) != end(hash))
			return false;

		hash.insert(cur);
	}
	return true;
}

int main() {
	int num;
	cin >> num;
	isHappy(num) ? cout << "HAPPY\n" : cout << "UNHAPPY\n";
}
