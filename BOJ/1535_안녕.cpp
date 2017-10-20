#include <iostream>
#include <algorithm>

using namespace std;

int n;
int L[21];
int J[21];

int func(int pos, int hp) {
	if(hp <= 0) { return -987654321; }
	if(pos == n) {
		return 0;
	}
	// ���粨�� ���ſ� �Ȱ�����  max�� ã�ƶ�
	return max(func(pos + 1, hp - L[pos]) + J[pos], func(pos + 1, hp));
};

int main() {
	
	int hp = 100;
	int happy = 0;

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> L[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> J[i];
	}
	cout<<func(0, 100);

	return 0;
}