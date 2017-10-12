#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	string str;
	int ret = 0;
	cin >> n;
	cin >> str;
	
	for(int i = 0; i < n; ++i){
		ret += str[i] - '0';
	}
	
	cout << ret;
	return 0;
}