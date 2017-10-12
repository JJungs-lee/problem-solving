#include <iostream>
#include <math.h>
using namespace std;

int main(){

	int testCase;
	cin >> testCase;

	while(testCase--){
		double x1, y1;		//������
		double x2, y2;		//������
		int n;			//�༺�� ����

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> n;

		// �༺ �߽�, ������
		int ret = 0;
		double cx, cy, r;

		/*�ѿ��� ���� �������� ������� ���´� �� 4����.
			1. ����ڰ� �� �ȿ� ���� ���
			1 - 1) �������� �� �ȿ� �ִ� == ī��Ʈ x
			1 - 2) �������� �� �ۿ� �ִ� == ī��Ʈ o

			2. ����ڰ� �� �ۿ� �ִ�.
			2 - 1) �������� �� �ȿ� �ִ� == ī��Ʈ o
			2 - 2) �������� �� �ۿ� �ִ� == ī��Ʈ x
		*/
		for(int i = 0; i < n; ++i){
			cin >> cx >> cy >> r;
			double a = sqrt(pow(cx - x1, 2) + pow(cy - y1, 2));
			double b = sqrt(pow(cx - x2, 2) + pow(cy - y2, 2));
			if(a<r && b>r){
				ret++;
			} else if(a > r && b < r){
				ret++;
			}
		}
	
		cout << ret << endl;

	}

	return 0;
}