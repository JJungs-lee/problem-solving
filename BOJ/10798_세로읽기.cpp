#include <iostream>
#include <string>

using namespace std;

int main() {
	string str[5];
	
	for(int i=0; i<5; ++i){
		cin>>str[i];
	}
	
	for(int x=0; x<15; ++x){
		//str ¼øÈ¸
		for(int y=0; y<5; ++y){
			if(str[y].size() <= x){
				continue;
			} else{
				cout<<str[y][x];
			}
		}
	}
	cout<<endl;
	
	return 0;
}