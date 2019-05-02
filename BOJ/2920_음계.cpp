#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int num;
	int flag_asc = 0;
	int flag_des = 0;
	
	for(int i = 0; i < 8; ++i){
		cin >> num;	
		if(num == i+1){
			flag_asc++;		
		} else if (num+i == 8){
			flag_des++;
		}
	}
    
	if(flag_asc == 8){
		cout<<"ascending"<<endl;
	}else if(flag_des == 8){
		cout<<"descending"<<endl;
	}else {
		cout<<"mixed"<<endl;
	}
	return 0;
}