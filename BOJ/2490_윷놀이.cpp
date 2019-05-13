#include <iostream>

using namespace std;

int main(){
	int tc = 3;
	char arr[5] = {'E','A','B','C','D'};
	while(tc--){
		int count = 0;
		int num;
		for(int i=0; i<4; ++i){
			cin>> num;
			if(num == 0) count++;
		}
		cout<< arr[count]<<endl;
	}
	return 0;
}