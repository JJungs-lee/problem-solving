#include <iostream>
#include <string>

using namespace std;

int main(){

	int count = 0;
	int i, j;
	string str;

	getline(cin, str);

	for(i = 0; i < str.size(); ++i){
		if(str[i] != ' '){
			count++;

			for(j = i; j < str.size(); ++j){
				if(str[j] == ' ') {
					i = j;
					break;
				}
			}
		}
		if(j == str.size()) break;
	}
	cout << count << endl;

	return 0;
}
