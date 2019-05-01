#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int num;
	string str;
	vector<int> v;
	for(int i=0; i<3; ++i){
		cin>> num;
		v.push_back(num);
	}
	cin>> str;
	sort(v.begin(),v.end());
	
	for(int i=0; i<3; ++i){
		cout<<v[str[i]-'A']<<" ";
	}

	return 0;
}