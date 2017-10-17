#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if(n % 2 == 0) {
		cout << "I LOVE CBNU" << endl;
	} else {
		int mid = n / 2;
		for(int i = 0; i < n; ++i) {
			cout << "*";
		}
		cout << endl;
		
		for(int i = 0; i < mid+1; ++i) {
			for(int j = 0; j < n; ++j) {
				if(j == mid - i || j == mid + i) {
					cout << "*";
					if(j == mid + i)break;
				} else {
					cout << " ";
				}
			}
			cout << endl;
		}	
	}

	return 0;
}