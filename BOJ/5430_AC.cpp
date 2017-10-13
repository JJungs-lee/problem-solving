#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <deque>
using namespace std;

int main() {
	// �ΰ��� �Լ� R(������) D(������)
	// R = �迭�� �ִ� ������ ������ ������ �Լ�
	// D = ù��° ���ڸ� ������ �Լ�(��������� ����)

	int testCase;
	cin >> testCase;

	while(testCase--) {
		int n;
		string str;
		string data;
		bool front = true;
		bool checkError = false;
		deque<int> deq;

		// ������ �Լ� ����
		cin >> str;
		// �迭�� ����ִ� ���� ����
		cin >> n;
		// �迭 ����
		cin >> data;
		int num = 0;
		for(int k = 0, i = 1; k<n && i<data.size(); ++i) {
			if(data[i] >= '0' && data[i] <= '9') {
				num = num * 10 + (data[i] - '0');
			} else {
				deq.push_back(num);
				num = 0;
				k += 1;
			} 
		}
		// �Լ� �����ϱ�
		for(int i = 0; i < str.size(); ++i) {
			if(str[i] == 'R') {
				front = !front;
			} else if(str[i] == 'D') {
				if(deq.size() == 0) {
					cout << "error" << endl;
					checkError = true;
					break;
				} else {
					if(front) {
						deq.pop_front();
					} else {
						deq.pop_back();
					}
					
				}
			}
		}
		if(!checkError) {
			cout << "[";
			if(front == true) {
				for(int i = 0; i < deq.size(); ++i) {

					cout << deq[i];
					if(i != deq.size() - 1) {
						cout << ",";
					}
				}
			} else {
				for(int i = deq.size() - 1; i >= 0; --i) {

					cout << deq[i];
					if(i != 0) {
						cout << ",";
					}
				}
			}
			cout << "]" << endl;
		}
	}

	return 0;
}