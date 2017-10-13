#include <iostream>
#include <deque>

using namespace std;

int main() {
	//n = ť�� ũ��, m = �̾Ƴ������ϴ� ���� ����
	int n, m;
	int cnt = 0;
	cin >> n >> m;
	
	deque<int> deq;

	// ��ť�� ���ֱ�
	for(int i = 0; i < n; ++i) {
		deq.push_back(i + 1);
	}

	// �̾Ƴ���
	for(int i = 0; i < m; ++i) {
		int num;
		int idx = 1;
		cin >> num;

		//��ġ ã��
		for(deque<int>::iterator iter = deq.begin(); iter != deq.end(); ++iter) {
			if(num == *iter) {
				break;
			}
			idx++;
		}
		int left = idx - 1;
		int right = deq.size() - idx + 1;
		
		// �������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� a2, ..., ak, a1�� �ȴ�.
		if(left < right) {
			for(int i = 0; i < left; ++i) {
				deq.push_back(deq.at(0));
				deq.pop_front();
				cnt++;
			}
			deq.pop_front();
		} else {
			//���������� �� ĭ �̵���Ų��. �� ������ �����ϸ�, a1, ..., ak�� ak, a1, ..., ak-1�� �ȴ�.
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