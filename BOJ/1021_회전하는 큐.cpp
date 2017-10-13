#include <iostream>
#include <deque>

using namespace std;

int main() {
	//n = 큐의 크기, m = 뽑아내려고하는 수의 개수
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	
	deque<int> deq;

	// 덱큐에 값넣기
	for(int i = 0; i < n; ++i) {
		deq.push_back(i + 1);
	}

	// 뽑아내기
	for(int i = 0; i < m; ++i) {
		int num;
		int idx = 1;
		cin >> num;

		//위치 찾음
		for(deque<int>::iterator iter = deq.begin(); iter != deq.end(); ++iter) {
			if(num == *iter) {
				break;
			}
			idx++;
		}
		int left = idx - 1;
		int right = deq.size() - idx + 1;
		
		// 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
		if(left < right) {
			for(int i = 0; i < left; ++i) {
				deq.push_back(deq.at(0));
				deq.pop_front();
				cnt++;
			}
			deq.pop_front();
		} else {
			//오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
			for(int i = 0; i < right; ++i) {
				deq.push_front(deq.at(deq.size()-1));
				deq.pop_back();
				cnt++;
			}
			deq.pop_front();
		}
	}

	cout << cnt << endl;

	return 0;
}