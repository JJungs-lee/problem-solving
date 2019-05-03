#include <iostream>
using namespace std;

int main(){
	int num;
	cin >> num;
	
	if(90 <= num || 100 <= num ){
		cout<<"A"<<endl;	
	}else if(80 <= num || 89 <= num ){
		cout<<"B"<<endl;	
	}else if(70 <= num || 79 <= num ){
		cout<<"C"<<endl;	
	}else if(60 <= num || 69 <= num ){
		cout<<"D"<<endl;	
	}else {
		cout<<"F"<<endl;	
	}
	
    return 0;
}