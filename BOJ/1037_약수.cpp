#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int cnt;
	int num;
	vector<int> v;

	cin >> cnt;
	for(int i = 0; i < cnt; ++i){
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cout << v.front() *v.back();
	return 0;
}