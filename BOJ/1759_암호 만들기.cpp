#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<char> vec;
int L;
int C;
char arrC[15];
bool check[15];

void DFS(int count){

	if(count == L){
		//자음,모음 갯수 카운트
		int consonant = 0, vowel = 0;
		for(int i = 0; i<vec.size(); ++i) {
			if(vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u') vowel++;
			else consonant++;
		}
		//자음2개이상 모음 1개이상시 출력
		if(vowel >= 1 && consonant >= 2){
			for(int i = 0; i<vec.size(); ++i) cout << vec[i];
			cout << endl;
		}
	}
	// 1부터 돌면서 오름차순일때 진행
	for(int i = 1; i<C; ++i){
		if(!check[i] && vec[vec.size() - 1]<arrC[i]){
			check[i] = true;
			vec.push_back(arrC[i]);
			DFS(count + 1);
			check[i] = false;
			vec.pop_back();
		}
	}
}

int main(){
	cin >> L >> C;

	for(int i = 0; i<C; ++i) cin >> arrC[i];

	//오름차순으로 정렬
	sort(&arrC[0], &arrC[C]);

	//DFS에서 할려고했지만 문자가 오름차순으로 되는지 확인을 편하게 하기위해
	for(int i = 0; i<C; ++i){
		check[i] = true;
		vec.push_back(arrC[i]);
		DFS(1);
		check[i] = false;
		vec.pop_back();
	}
	return 0;
}