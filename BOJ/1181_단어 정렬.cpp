#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Data {
	string word;
	int length;
};

bool isLower(const Data &a, const Data &b);
bool isLowerWord(const Data &a, const Data &b);
bool isSame(const Data &a, const Data &b);

int main() {
	int n;
	Data d[20000];

	// input
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d[i].word;
		d[i].length = d[i].word.length();
	}

	stable_sort(&d[0], &d[n], isLowerWord);
	stable_sort(&d[0], &d[n], isLower);

	Data *it;
	it = unique(&d[0], &d[n], isSame);

	for (Data *i = &d[0]; i != it; ++i) {
		cout << i->word << endl;
	}
	return 0;
}

bool isLower(const Data &a, const Data &b) {
	return a.length < b.length;
}

bool isLowerWord(const Data &a, const Data &b) {
	return a.word < b.word;
}
bool isSame(const Data &a, const Data &b) {
	return a.word == b.word;
}