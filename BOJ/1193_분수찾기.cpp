#include <iostream>

using namespace std;

int main(){

	int n;
	//while (){
	cin >> n;
	int index = n;			//그줄의 몇번째 인지 확인 .
	int mother;
	int sun;

	int i;
	for(i = 1; index > i; ++i){
		index -= i;
	}
	//cout << 'i' << i << endl;
	//cout << "index" << index << endl;
	if(i % 2 == 0) {
		mother = i - index + 1;
		sun = index;
	} else {
		mother = index;
		sun = i - index + 1;
	}
	//cout << "TERM " << n << " IS " << sun << '/' << mother << endl;
	cout << sun << '/' << mother;
	//}

	return 0;
}