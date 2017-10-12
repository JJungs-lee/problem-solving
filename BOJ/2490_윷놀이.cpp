#include <iostream>

using namespace std;

int main(){
	int n;

	for(int i = 0; i<3; ++i){
		int cnt = 0;
		for(int j = 0; j<4; ++j){
			cin >> n;
			n == 0 ? cnt++ : cnt;
		}
		switch(cnt){
			case 0: cout << 'E' << endl; break;
			case 1: cout << 'A' << endl; break;
			case 2: cout << 'B' << endl; break;
			case 3: cout << 'C' << endl; break;
			case 4: cout << 'D' << endl; break;
		}
	}
	return 0;
}