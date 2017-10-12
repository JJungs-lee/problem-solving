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
		//����,���� ���� ī��Ʈ
		int consonant = 0, vowel = 0;
		for(int i = 0; i<vec.size(); ++i) {
			if(vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u') vowel++;
			else consonant++;
		}
		//����2���̻� ���� 1���̻�� ���
		if(vowel >= 1 && consonant >= 2){
			for(int i = 0; i<vec.size(); ++i) cout << vec[i];
			cout << endl;
		}
	}
	// 1���� ���鼭 ���������϶� ����
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

	//������������ ����
	sort(&arrC[0], &arrC[C]);

	//DFS���� �ҷ��������� ���ڰ� ������������ �Ǵ��� Ȯ���� ���ϰ� �ϱ�����
	for(int i = 0; i<C; ++i){
		check[i] = true;
		vec.push_back(arrC[i]);
		DFS(1);
		check[i] = false;
		vec.pop_back();
	}
	return 0;
}