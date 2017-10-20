#include <iostream>
#include <algorithm>
using namespace std;

int n;
int graph[10001];
int dp[10001];


int main() {
	
	cin >> n;

	for(int i = 1; i <= n; ++i) {
		cin >> graph[i];
	}
	dp[1] = graph[1];
	dp[2] = graph[1] + graph[2];

	// 3가지 경우
	// 1. 안마시는경우 >> dp[n] = dp[n-1]
	// 2. 이번차례가 1잔연속 마시는 경우 
	//    즉, n-1번째는 마시지 않고 그아래는 마셨는지 모름 
    //	    >> dp[n] = dp[n-2] + graph[n]
	// 3. 이번차례가 2잔연속 마시는 경우 
	//    즉, n-1은 마셨고, n-2는 마시면 안됨(연속3잔 못먹으니)
	//      >> dp[n] = graph[n] + graph[n-1] + dp[n-3]

	for(int i = 3; i <= n; ++i) {
		dp[i] = max(dp[i - 1], max(graph[i] + dp[i - 2], graph[i] + graph[i - 1] + dp[i - 3]));
	}
	cout << dp[n] << endl;
	return 0;
}