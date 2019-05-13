#include <iostream>

using namespace std;

int main(){
	int n, num, ret = 0;
	cin >> n;
	for(int i=0; i<5; ++i){
		cin >> num;
		if(n == num) ret++;
	}
	cout << ret;
	return 0;
}