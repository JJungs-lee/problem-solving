#include <iostream>

using namespace std;

int main() {
	//�����̰� �������ô� ��Ģ
	// ���ô� ������ ���� > ���� > �ٳ��� ������ ���ư�
	
	//���������� �� 
	int n;
	// 0�� ����������� �Ĵ� ����, 
	// 1�� ���ڿ������� �Ĵ� ����, 
	// 2�� �ٳ����������� �Ĵ� ����
	int mart[1001];

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> mart[i];
	}
	int flag = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(flag == mart[i]) {
			flag++;
			cnt++;
			if(flag >= 3) {
				flag = 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}