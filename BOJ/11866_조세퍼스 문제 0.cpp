#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){

	int n, m;
	
	cin >> n >> m;

	queue<int> q;
	vector<int> v;

	for(int i = 0; i < n; ++i){
		q.push(i + 1);
	}
	int cnt = 1;
	
	while(!q.empty()){
		int num = q.front();
		q.pop();
		if(cnt == m){
			v.push_back(num);
			cnt = 1;
		} else{
			q.push(num);
			cnt++;
		}
	}

	for(int i = 0; i < v.size(); ++i){
		if(i == 0){
			cout << "<";
		}
		cout << v[i];
		if(i == v.size() - 1){
			cout << ">";
		} else{
			cout << ", ";
		}
	}
	return 0;
}