#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int cache[1001];

// �˰��� �����ذ� ������ ������ �ڵ�
// ���ȣ���Ҷ����� �츮�� start���� �ڿ��ְ� ū ���� �� �ϳ��� ���� ���ڷ� ����.
int slove(int start){
	int& ret = cache[start];

	if(ret != -1) return ret;

	ret = 1;

	for(int next = start + 1; next <= n; ++next) {
		if(arr[start] < arr[next]) {
			ret = max(ret, slove(next)+1);
		}

	}
	return ret;
	
}
int main() {
	int cnt = 0;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
		cache[i] = -1;
	}
	for(int i = 1; i <= n; ++i) {

		cnt = max(cnt, slove(i));
	}
	cout << cnt;
	return 0;
}
/*
<���� Ǭ ���>
1. �� ���� ���� ���� ������ �ڽ� ���� ������ ������ ���ƺ��� �� �� �ִ��� ������ �ڽ��� �ִ� ���̸� ���ϴ� �����̴�.
2. �׷��� �� �κи��� ������ ������ �迭�� �˻��� �ؾ��Ѵ�. ���� �������ڸ� �Ʒ� �׸��� ����.
3. �׷��� ���⼭ �ٸ����� �� �߿��� ���� �� ������ ���� �̴� �ű� ������ �� ���̿� ���ؼ� �ִ밪�� ������ ������ ����Ѵ�.
#include <stdio.h>

int main(void) {
	int N;
	int Dp[1010] = {};
	int A[1010] = {};
	int max = 0;
	scanf("%d", &N);

	for(int i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) {
		int min = 0;
		for(int j = 0; j < i; j++) {
			if(A[i]>A[j]) {
				if(min < Dp[j])
					min = Dp[j];
			}
		}
		Dp[i] = min + 1;
		if(max < Dp[i])
			max = Dp[i];
	}

	printf("%d\n", max);

}


 
��ó: http ://wootool.tistory.com/96 [������������]
*/