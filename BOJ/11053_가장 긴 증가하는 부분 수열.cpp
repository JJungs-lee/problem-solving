#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1001];
int cache[1001];

// 알고리즘 문제해결 전략에 나오는 코드
// 재귀호출할때마다 우리는 start보다 뒤에있고 큰 수들 중 하나들 다음 숫자로 결정.
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
<문제 푼 요령>
1. 이 문제 같은 경우는 현재의 자신 값을 과거의 값들을 돌아봐서 그 중 최대의 값으로 자신의 최대 길이를 정하는 문제이다.
2. 그래서 각 부분마다 과거의 저장한 배열을 검색을 해야한다. 쉽게 설명하자면 아래 그림과 같다.
3. 그래서 여기서 다른점은 이 중에서 가장 긴 길이의 값을 뽑는 거기 때문에 각 길이에 대해서 최대값이 나오면 갱신해 줘야한다.
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


 
출처: http ://wootool.tistory.com/96 [우투리와툴툴]
*/