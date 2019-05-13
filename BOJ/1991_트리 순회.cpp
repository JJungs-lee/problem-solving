#include <iostream>
using namespace std;

char node[26][2];

void Preoder(char c){
	cout<<c;
	if(node[c-'A'][0] != '.'){
		Preoder(node[c-'A'][0]);
	}
	if(node[c-'A'][1] != '.'){
		Preoder(node[c-'A'][1]);
	}
}
void inoder(char c){
	if(node[c-'A'][0] != '.'){
		inoder(node[c-'A'][0]);
	}
	cout<<c;
	if(node[c-'A'][1] != '.'){
		inoder(node[c-'A'][1]);
	}
}
void Postoder(char c){
	if(node[c-'A'][0] != '.'){
		Postoder(node[c-'A'][0]);
	}
	if(node[c-'A'][1] != '.'){
		Postoder(node[c-'A'][1]);
	}
	cout<<c;
}

int main() {
	
	for(int i=0; i<26; ++i){
		for(int j=0; j<2; ++j){
			node[i][j] = '.';
		}
	}
	int num;
	char c;
	cin >> num;
	
	for(int i=0; i<num; ++i){
		cin >> c;
		cin >> node[c-'A'][0] >> node[c-'A'][1];
	}
	Preoder('A');
	cout<<endl;
	inoder('A');
	cout<<endl;
	Postoder('A');
	
	return 0;
}