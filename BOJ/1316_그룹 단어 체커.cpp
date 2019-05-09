#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int tc;
	
	cin>>tc;
	int ret = 0;
	while(tc--){
		string str;
		vector<bool> v(26,false);
		bool flag = false;
		cin >> str;

		char prev, next;
		prev = next = str[0];
		v[prev-'a'] = true;

		for(int i=1; i<str.size(); ++i){
			next = str[i];
			if(prev != next){
				if(v[next-'a']) {
					flag = true;
					break;
				}
				v[next-'a'] = true;
			}
			prev = str[i];
		}
		if(!flag) ret++;
	}
	
	cout << ret << endl;
	return 0;
}