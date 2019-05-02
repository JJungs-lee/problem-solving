#include <iostream>

using namespace std;

int main() {
	int n, sugar_3 = 0;
	cin >> n;
	
	while(1){
		if(n%5 == 0){
			cout<< n/5 + sugar_3 <<endl; 
			break;
		} else if(n <= 0) {
			cout<< "-1" <<endl;
			break;
		}
		sugar_3++;
		n -= 3;
	}

	return 0;
}