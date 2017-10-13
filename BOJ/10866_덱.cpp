#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(){

	int testCase;
	int num; 
	string str;
	
	cin >> testCase;
	deque<int> deq;
	while(testCase--){
		cin >> str;
		if(str == "push_front") {
			cin >> num;
			deq.push_front(num);
		} else if(str == "push_back") {
			cin >> num;
			deq.push_back(num);
		} else if(str == "pop_front") {
			if(!deq.empty()) {
				cout << deq.front() << endl;
				deq.pop_front();
			} else {
				cout << "-1" << endl;
			}
		} else if(str == "pop_back") {
			if(!deq.empty()) {
				cout << deq.back() << endl;
				deq.pop_back();
			} else {
				cout << "-1" << endl;
			}
		} else if(str == "size") {
			cout << deq.size() << endl;
		} else if(str == "empty") {
			if(!deq.empty()) {
				cout << "0" << endl;
			} else {
				cout << "1" << endl;
			}
		} else if(str == "front") {
			if(!deq.empty()) {
				cout << deq.front() << endl;
			} else {
				cout << "-1" << endl;
			}
		} else if(str == "back") {
			if(!deq.empty()) {
				cout << deq.back() << endl;
			} else {
				cout << "-1" << endl;
			}
		}
	}

	return 0;
}