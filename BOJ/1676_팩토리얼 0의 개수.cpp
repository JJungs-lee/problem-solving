#include <iostream>

using namespace std;

int main() {
	int n;
	int cnt = 0;
	cin >> n;
	// 0�� ������ 2*5�� ������ �������µ�
	// 2�� ���ĳ��� 5�� ������ 5�� ������������� ī��Ʈ
	// 5�� 1��, 25�� 2��, 125�� 3�� �̹Ƿ� �̷��� �ؼ� ī��Ʈ
	for(int i = 1; i <= n; i++) {
		if(i % 5 == 0)cnt++;
		if(i % 25 == 0)cnt++;
		if(i % 125 == 0)cnt++;
	}

	cout << cnt;
	return 0;
}