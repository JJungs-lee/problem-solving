#include <iostream>

using namespace std;

int main(){
	//�ִ밪 M
	//��� ������  ����/M*100���� ����
	//������ ����
	
	int n;
	double m = 0;
	double arr[1001];
	double ret = 0;
	cin >> n;
	//���� �Է¹���
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
		if(arr[i] > m){
			m = arr[i];
		}
	}

	//���� ����
	for(int i = 0; i < n; ++i){
		ret += arr[i] / m * 100;
	}
	cout << fixed;
	cout.precision(2);
	cout << ret / n << endl;

	return 0;
}