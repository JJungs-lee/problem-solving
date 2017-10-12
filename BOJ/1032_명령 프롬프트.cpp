#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
	int num;
	cin >> num;

	string str;
	vector<string> v;
	for(int i = 0; i<num; ++i){
		cin >> str;
		v.push_back(str);
	}
	char answer[255];
	char tmp;
	bool diff = false;
	for(int i = 0; i<v[0].size(); ++i){
		tmp = v[0][i];
		for(int j = 1; j<num; ++j){
			if(tmp == v[j][i]) continue;
			else diff = true;
		}
		if(diff) answer[i] = '?';
		else if(tmp == '.') answer[i] = '.';
		else answer[i] = tmp;
		diff = false;
	}

	for(int i = 0; i < v[0].size(); ++i){
		cout << answer[i];
	}

	return 0;
}