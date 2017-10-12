#include <iostream>

using namespace std;

int main(){

	int n;

	cin >> n;

	for(int i = n; i>0; --i){
		for(int j = 0; j<i - 1; ++j) cout << ' ';
		for(int j = 0; j<2 * (n - i + 1) - 1; ++j) cout << '*';
		cout << endl;
	}
	return 0;
}
