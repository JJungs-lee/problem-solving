#include <iostream>
#include <queue>

using namespace std;

int main(){
	// 현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
	// 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 
	// 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다.그렇지 않다면 바로 인쇄를 한다.

	int testCase;
	cin >> testCase;
	
	while(testCase--){
		// 문서의 수 n , 몇번째로 인쇄되었는지 궁금한 문서 queue의 위치
		int n, m;
		int num;
		cin >> n >> m;
		//인덱스, 중요도
		queue< pair<int,int> > q;
		priority_queue<int> pq;
		//문서의 수만큼 중요도를 받음
		for(int i = 0; i < n; ++i){
			cin >> num;
			
			pair<int, int> p;
			p = make_pair(i, num);
				
			pq.push(num);
			q.push(p);
		}

		//시뮬레이션
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