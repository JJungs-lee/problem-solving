#include <iostream>

using namespace std;

int main(){

	int num;
	int sum;

	for(int i = 0; i<5; ++i){
		cin >> num;
		sum += (num*num) % 10;
	}
	cout << sum % 10 << endl;

	return 0;
}
