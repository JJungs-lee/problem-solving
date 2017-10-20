#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int cache[1001];

int solve(int start) {
	int &ret = cache[start];

	if(ret != -1) {
		return ret;
	}
	ret = 1;
	for(int next = start + 1; next <= n; ++next) {
		if(arr[start] > arr[next]) {
			ret = max(ret, solve(next) + 1);
		}
	}
	return ret;
}

int main() {
	
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
		cache[i] = -1;
	}
	
	for(int i = 1; i <= n; ++i) {
		cnt = max(cnt, solve(i));
	}
	cout << cnt << endl;
	return 0;
}

// 다른 풀이법
//#include <iostream>
//
//using namespace std;
//int n;
//int arr[1001];
//int cache[1001];
//
//int main() {
//	cin >> n;
//	int cnt = 0;
//	int max = 0;
//	for(int i = 1; i <= n; ++i) {
//		cin >> arr[i];
//		cache[i] = 0;
//	}
//	
//	for(int i = 1; i <= n; ++i) {
//		int min = 0;
//		for(int j = 0; j < i; ++j) {
//			//이전거를 비교하는 문장
//			if(arr[i] < arr[j]) {
//				if(min < cache[j]) {
//					min = cache[j];
//				}
//			}
//		}
//		cache[i] = min + 1;
//		if(max < cache[i]) {
//			max = cache[i];
//		}
//	}
//	cout << max;
//	return 0;
//}