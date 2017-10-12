#include <iostream>
#include <string>
#include <memory.h>

using namespace std;

int main(){
	int n;
	int arr[27];
	bool go = false;
	memset(arr, 0, sizeof(arr));
	cin >> n;

	while(n--){
		string str;
		cin >> str;
		arr[str[0] - '0' - 49]++;
	}

	for(int i = 0; i < 27; ++i){
		if(arr[i] > 4) {
			cout << char(i + 97);
			go = true;
		}
	}
	if(!go) cout << "PREDAJA" << endl;
	return 0;
}