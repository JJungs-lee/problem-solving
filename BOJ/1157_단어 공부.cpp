#include <iostream>
#include <string>
#include <cctype>         //by tolower
using namespace std;

int main(){
	string str;
	int arr[26];

	int maxNum;
	int maxIndex = 0;
	bool dupleCheck = false;
	cin >> str;

	//init
	for(int i = 0; i<26; ++i) arr[i] = 0;

	//change capital
	for(int i = 0; i<str.size(); ++i){
		arr[tolower(str[i]) - 'a']++;
	}

	//find max Number
	maxNum = arr[0];
	for(int i = 0; i<26; ++i){
		if(maxNum < arr[i]) {
			maxNum = arr[i];
			maxIndex = i;
		}
	}

	for(int i = 0; i<26; ++i) {
		if((maxNum == arr[i]) && (maxIndex != i)){
			dupleCheck = true;
			break;
		}
	}
	dupleCheck ? cout << '?' : cout << char(maxIndex + 'A');

	return 0;
}
