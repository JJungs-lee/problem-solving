#include <iostream>

using namespace std;

int main(){

	int problem;
	int sum = 0;
	int val = 1;

	cin >> problem;

	for(int i = 0; i<problem; ++i){
		int num;
		cin >> num;

		if(num == 1){
			sum += (num*val);
			val++;
		} else val = 1;
	}

	cout << sum << endl;

	return 0;
}