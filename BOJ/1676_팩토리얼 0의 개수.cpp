#include <iostream>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	// 0의 개수는 2*5의 개수로 정해지는데
	// 2는 넘쳐나고 5가 적으니 5로 나누어떨어질때만 카운트
	// 5는 1개, 25는 2개, 125는 3개 이므로 이렇게 해서 카운트
	for (int i = 1; i <= n; i++) {
		if (i % 5 == 0) cnt++;
		if (i % 25 == 0) cnt++;
		if (i % 125 == 0) cnt++;
	}

	cout << cnt;
	return 0;
}