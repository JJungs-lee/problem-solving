#include <iostream>

using namespace std;

int main(){

	int n;

	cin >> n;

	//윗부분 출력
	for(int i = 0; i<n - 1; ++i){
		for(int j = 0; j<2 * n; ++j){
			if(i<j && j<2 * n - i - 1) cout << ' ';
			else cout << '*';
		}
		cout << endl;
	}

	for(int i = n - 1; i >= 0; --i){
		for(int j = 0; j<2 * n; ++j){
			if(i<j && j<2 * n - i - 1) cout << ' ';
			else cout << '*';
		}
		cout << endl;
	}

	return 0;
}
