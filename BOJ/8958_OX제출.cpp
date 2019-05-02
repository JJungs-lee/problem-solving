#include <iostream>
#include <string>
using namespace std;

int main() {
	int tc;
	
	cin >> tc;
	while(tc--){
		string str;
		cin>> str;
		int num = 1;
		int sum = 0;
		
		for(auto c : str){
			if(c == 'O'){
				sum += num;
				num++;
			}else{
				num = 1;
			}
		}
		cout << sum << endl;
	}
	
	return 0;
}