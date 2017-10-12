#include <iostream>
#include <cmath>		//pow
#include <cstring>		//strlen
#include <vector>

using namespace std;

int main(){

	char two[1000001];
	vector<int> bin;

	int sum = 0;
	int count = 0;
	cin >> two;

	for(int i = strlen(two) - 1; i >= 0; --i){
		//2ÀÇ 0½Â
		if(count == 0){
			sum += (two[i] - '0') * pow(2, 0);
			count++;
			if(i == 0) bin.push_back(sum);

		}
		//2ÀÇ 1½Â
		else if(count == 1){
			sum += (two[i] - '0') * pow(2, 1);
			count++;
			if(i == 0) bin.push_back(sum);

		}
		//2ÀÇ 2½Â
		else {
			sum += (two[i] - '0') * pow(2, 2);
			bin.push_back(sum);
			count = 0;
			sum = 0;
		}
	}

	for(int i = bin.size() - 1; i >= 0; --i){
		cout << bin[i];
	}

	return 0;
}