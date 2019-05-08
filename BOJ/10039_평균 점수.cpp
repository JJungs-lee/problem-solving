#include <iostream>

using namespace std;

int main(){
	int num;
	int sum = 0;
	for(int i=0; i<5; ++i){
		cin>>num;
		if(num < 40)
			sum += 40;
		else 
			sum += num;
	}
	cout << sum / 5 << endl;

	return 0;
}