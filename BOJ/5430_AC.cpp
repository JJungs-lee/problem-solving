#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <deque>
using namespace std;

int main() {
	// 두가지 함수 R(뒤집기) D(버리기)
	// R = 배열에 있는 숫자의 순서를 뒤집는 함수
	// D = 첫번째 숫자를 버리는 함수(비어있으면 에러)

	int testCase;
	cin >> testCase;

	while(testCase--) {
		int n;
		string str;
		string data;
		bool front = true;
		bool checkError = false;
		deque<int> deq;

		// 수행할 함수 받음
		cin >> str;
		// 배열에 들어있는 수의 개수
		cin >> n;
		// 배열 구성
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
		// 함수 동작하기
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