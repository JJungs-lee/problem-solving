#include <iostream>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

int main(){
	int testCase;
	cin >> testCase;

	while(testCase--){
		//N �����Ǽ�, M ����� ����
		
		int N, M;
		cin >> N >> M;
		
		for(int i = 0; i < M; ++i){
			int a,b;
			cin >> a >> b;
		}
	
		cout << N-1 << endl;
	}
	
	return 0;
}