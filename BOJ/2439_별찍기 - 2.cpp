#include <iostream>

using namespace std;

int main(){

	int n;

	cin >> n;

	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j<i; ++j){
			cout << ' ';
		}
		for(int j = i; j<n; ++j){
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}
