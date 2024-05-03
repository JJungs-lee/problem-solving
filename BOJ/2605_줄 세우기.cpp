#include <iostream>
using namespace std;

int main() {
	int stu[100], ball;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		stu[i] = i + 1;
		cin >> ball;
		for (int j = i; j > i - ball; j--)
			swap(stu[j], stu[j - 1]);
	}
	for (int i = 0; i < n; i++)
		cout << stu[i] << " ";

	return 0;
}