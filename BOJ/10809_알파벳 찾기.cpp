#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string str;
	vector<int> arr(26,-1);
	
	cin >> str;
	for(int i=0; i<str.size(); ++i){
		if(arr[str[i]-'a'] == -1){
			arr[str[i]-'a'] = i; 
		}
	}
	for (auto num: arr){
		cout<<num<<" ";
	}
	return 0;
}