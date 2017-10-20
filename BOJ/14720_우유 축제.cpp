#include <iostream>

using namespace std;

int main() {
	//영학이가 우유마시는 규칙
	// 마시는 순서는 딸기 > 초코 > 바나나 순으로 돌아감
	
	//우유가게의 수 
	int n;
	// 0은 딸기우유만을 파는 가게, 
	// 1은 초코우유만을 파는 가게, 
	// 2는 바나나우유만을 파는 가게
	int mart[1001];

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> mart[i];
	}
	int flag = 0;
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		if(flag == mart[i]) {
			flag++;
			cnt++;
			if(flag >= 3) {
				flag = 0;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}