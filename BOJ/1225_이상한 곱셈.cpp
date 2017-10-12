#include <iostream>
#include <string>
using namespace std;

int main(){

	string a;
	string b;
	unsigned int sum = 0;
	unsigned int bSum = 0;

	cin >> a >> b;

	for(int i = 0; i < b.size(); ++i){
		bSum += (b[i] - '0');
	}

	for(int i = 0; i < a.size(); ++i){
		sum += (a[i] - '0')*bSum;
	}
	cout << sum << endl;

	return 0;
}