#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int calcStr(string str){
	int ret = 0;
	for(int i = 0; i < str.size(); ++i){
		if(str[i] >= 'a' && str[i] <= 'z') ret += str[i] - 'a' + 1;
		else{
			ret += str[i] - 'A' + 27;
		}
	}
	return ret;
}
bool findSosu(int num){
	int n = sqrt(num);

	if(num == 1 || num == 2) return true;
	if(num % 2 == 0) return false;

	for(int i = 3; i < n; ++i){
		if(num %i == 0) return false;
	}
	return true;
}

int main(){
	string str;

	cin >> str;

	findSosu(calcStr(str)) ? cout << "It is a prime word." : cout << "It is not a prime word.";

	return 0;
}