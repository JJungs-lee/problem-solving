#include <iostream>
#include <queue>

using namespace std;

int main(){
	// ���� Queue�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�.
	// ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, 
	// �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�.�׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.

	int testCase;
	cin >> testCase;
	
	while(testCase--){
		// ������ �� n , ���°�� �μ�Ǿ����� �ñ��� ���� queue�� ��ġ
		int n, m;
		int num;
		cin >> n >> m;
		//�ε���, �߿䵵
		queue< pair<int,int> > q;
		priority_queue<int> pq;
		//������ ����ŭ �߿䵵�� ����
		for(int i = 0; i < n; ++i){
			cin >> num;
			
			pair<int, int> p;
			p = make_pair(i, num);
				
			pq.push(num);
			q.push(p);
		}

		//�ùķ��̼�
		int cnt = 0;
		while(!q.empty()){
			
			int idx = q.front().first;
			int importance = q.front().second;
			q.pop();

			if(importance == pq.top()){
				cnt++;
				pq.pop();
				if(idx == m){
					cout << cnt << endl;
					break;
				}
			} else{
				q.push(make_pair(idx, importance));
			}
		}

	}
	return 0;
}