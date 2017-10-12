#include <iostream>

using namespace std;

int main(){
	int num;
	int firstN;
	//10의 자리,1의 자리
	int ten, one;
	int cnt = 0;

	cin >> num;
	firstN = num;
	while(1){
		if(firstN == num && cnt != 0) break;
		ten = num / 10;
		one = num % 10;
		num = one * 10 + (ten + one) % 10;

		cnt++;
	}
	cout << cnt;
	return 0;
}