#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct data
{
	string word;
	int length;
};

bool isLower(const data &a, const data &b);
bool isLowerWord(const data &a, const data &b);
bool isSame(const data &a, const data &b);

int main(){

	int n;
	data d[20000];

	//input
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> d[i].word;
		d[i].length = d[i].word.length();
	}

	stable_sort(&d[0], &d[n], isLowerWord);
	stable_sort(&d[0], &d[n], isLower);

	data *it;
	it = unique(&d[0], &d[n], isSame);

	for(data* i = &d[0]; i != it; ++i){
		cout << i->word << endl;
	}
	return 0;
}

bool isLower(const data &a, const data &b){
	return a.length < b.length;
}

bool isLowerWord(const data &a, const data &b){
	return a.word < b.word;
}
bool isSame(const data &a, const data &b){
	return a.word == b.word;
}